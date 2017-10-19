/* 
 * File:   CursWin.cpp
 * Author: Josh
 * 
 * Created on June 4, 2012, 10:15 AM
 */

#include "CursWin.h"

int CursWin::numWindows = 0;

CursWin::CursWin() {
    if (!numWindows) {
        WINDOW* newWin;
        newWin = initscr();
        cbreak();
        refresh();
    }
    upperLeftRow = lowerRightRow = upperLeftCol = lowerRightCol = 0;
    writeEnabled = false;
    scrolling = true;
    onScreen = false;
    curRowPos = curColPos = 0;
    headerWidth = footerWidth = 0;
    maxRowPos = lowerRightRow - (upperLeftRow+2);
    maxColPos = lowerRightCol - (upperLeftCol+2);
    sv.expectingStreamParam = false;
    sv.precision = 2;
    sv.left_justified = true;
    sv.last = cflush;
    sv.field_enabled = false;
    sv.paramNum = 1;
    sv.invalid_input = false;
    sv.immErrorHandling = false;
    sv.min_filter = sv.max_filter = sv.fail_value = 0.0;
    sv.force_range = sv.min_active = sv.max_active = false;
    sv.filter_active = 0;
    isPopUp = false;
    restore = NULL;
    CursErrorOut = NULL;
    for (int i = 0; i < 1000; i++) {
        InputStream[i] = '\0';
    }
    numWindows++;
}
CursWin::CursWin(int ulr, int ulc, int lrr, int lrc, bool pop) {
    if (!numWindows) {
        WINDOW* newWin;
        newWin = initscr();
        cbreak();
        refresh();
    }
    upperLeftRow = ulr;
    upperLeftCol = ulc;
    lowerRightRow = lrr;
    lowerRightCol = lrc;
    isPopUp = pop;
    if (isPopUp) {
        int ySize = (lrr - ulr) + 1, xSize = (lrc - ulc) + 1;
        restore = new char*[ySize];
        for (int r = 0; r < ySize; r++) {
            restore[r] = new char[xSize];
            for (int c = 0; c < xSize; c++) {
                restore[r][c] = mvinch(ulr+r, ulc+c);
            }
        }
        DrawBoundingBox('#','#','#');
        ClearWin();
    }
    else {
        restore = NULL;
        DrawBoundingBox('-','|','+');
    }
    writeEnabled = true;
    scrolling = true;
    onScreen = true;
    curRowPos = curColPos = 0;
    headerWidth = footerWidth = 0;
    maxRowPos = lowerRightRow - (upperLeftRow+2);
    maxColPos = lowerRightCol - (upperLeftCol+2);
    sv.expectingStreamParam = false;
    sv.precision = 2;
    sv.left_justified = true;
    sv.last = cflush;
    sv.field_enabled = false;
    sv.paramNum = 1;
    sv.invalid_input = false;
    sv.immErrorHandling = false;
    sv.min_filter = sv.max_filter = sv.fail_value = 0.0;
    sv.force_range = sv.min_active = sv.max_active = false;
    sv.filter_active = 0;
    CursErrorOut = NULL;
    for (int i = 0; i < 1000; i++) {
        InputStream[i] = '\0';
    }
    numWindows++;
}
CursWin::CursWin(int ulr, int ulc, int lrr, int lrc, char rowC, char colC, char cornerC) {
    if (!numWindows) {
        WINDOW* newWin;
        newWin = initscr();
        cbreak();
        refresh();
    }
    upperLeftRow = ulr;
    upperLeftCol = ulc;
    lowerRightRow = lrr;
    lowerRightCol = lrc;
    DrawBoundingBox(rowC, colC, cornerC);
    writeEnabled = true;
    scrolling = true;
    onScreen = true;
    curRowPos = curColPos = 0;
    headerWidth = footerWidth = 0;
    maxRowPos = lowerRightRow - (upperLeftRow+2);
    maxColPos = lowerRightCol - (upperLeftCol+2);
    sv.expectingStreamParam = false;
    sv.precision = 2;
    sv.left_justified = true;
    sv.last = cflush;
    sv.field_enabled = false;
    sv.paramNum = 1;
    sv.invalid_input = false;
    sv.immErrorHandling = false;
    sv.min_filter = sv.max_filter = sv.fail_value = 0.0;
    sv.force_range = sv.min_active = sv.max_active = false;
    sv.filter_active = 0;
    CursErrorOut = NULL;
    for (int i = 0; i < 1000; i++) {
        InputStream[i] = '\0';
    }
    isPopUp = false;
    restore = NULL;
    numWindows++;
}

CursWin::~CursWin() {
    if (restore != NULL) {
        int ySize = (lowerRightRow - upperLeftRow) + 1, xSize = (lowerRightCol - upperLeftCol) + 1;
        for (int r = 0; r < ySize; r++) {
            for (int c = 0; c < xSize; c++) {
                mvaddch(upperLeftRow+r, upperLeftCol+c,restore[r][c]);
            }
            delete restore[r];
            restore[r] = NULL;
        }
        delete restore;
    }
    refresh();
    numWindows--;
    if (!numWindows) {
        endwin();
    }
}


// Private methods

void CursWin::DrawBoundingBox(char rowC, char colC, char cornerC) {
    mvaddch(upperLeftRow,upperLeftCol,cornerC);
    mvaddch(upperLeftRow,lowerRightCol,cornerC);
    mvaddch(lowerRightRow,upperLeftCol,cornerC);
    mvaddch(lowerRightRow,lowerRightCol,cornerC);
    for (int col = upperLeftCol+1; col < lowerRightCol; col++) {
        mvaddch(upperLeftRow,col,rowC);
        mvaddch(lowerRightRow,col,rowC);
    }
    for (int row = upperLeftRow+1; row < lowerRightRow; row++) {
        mvaddch(row,upperLeftCol,colC);
        mvaddch(row,lowerRightCol,colC);
    }
    refresh();
}

void CursWin::EraseWin(bool ref) {
    for (int r = upperLeftRow; r <=lowerRightRow; r++) {
        for (int c = upperLeftCol; c <= lowerRightCol; c++) {
            mvaddch(r,c,' ');
        }
    }
    if (ref) refresh();
    onScreen = false;
}

void CursWin::ScrollText() {
    int i;
    char temp[100];
    curRowPos--;
    if (scrolling) {
        int c;
        Move(headerWidth,0);
        for (int r = 1+headerWidth; r <= (maxRowPos-footerWidth); r++) {
            for (c = 0; c <= maxColPos; c++) {
                temp[c] = MvGetChar(r,c);
            }
            temp[c] = '\0';
            Writes(temp,false);
        }
    }
    for (i=0; i <= maxColPos; i++) temp[i] = ' ';
    temp[i] = '\0';
    Write(temp);
    curColPos = 0;
    curRowPos = (maxRowPos-footerWidth);   
}

void CursWin::HandleInputError(int expectedType) {
    const char* errMsg[2] = {
        "an integer",
        "a floating point"
    };
    int response;
    CursWin errorWin(upperLeftRow+curRowPos+1,upperLeftCol+1,upperLeftRow+curRowPos+7,lowerRightCol-1,true);
    errorWin << "Input error, was expecting " << errMsg[expectedType] << " value and the first token on the input stream did not match." << cnl
             << "Would you like to (1) reset the stream or " << cnl 
             << "                  (2) exit the program" << cnl
             << "--> " << cflush;
    response = errorWin.GetInt(1,2);
    if (response == 1) {
        sv.invalid_input = false;
    }
    else {
        endwin();
        exit(-1);
    }
}

char* CursWin::GetStr(char buf[]) {
    mvgetstr(curRowPos+upperLeftRow+1,curColPos+upperLeftCol+1,buf);
    curRowPos++;
    curColPos = 0;
    return &(buf[0]);
}

int CursWin::GetInt(int min_range, int max_range) {
    char buf[100];
    int ret_val = atoi(GetStr(buf));
    while ((min_range > ret_val) || (max_range < ret_val) || ((ret_val == 0) && (buf[0] != '0'))) {
        sprintf(buf,"Please enter a value in the range [%d - %d] --> ",min_range,max_range);
        MvWrite(curRowPos,0,buf);
        ret_val = atoi(GetStr(buf));
    }
    return ret_val;
}

double CursWin::GetDouble(double min_range, double max_range) {
    char buf[100];
    double ret_val = strtod(GetStr(buf), NULL);
    while ((min_range > ret_val) || (max_range < ret_val) || ((ret_val == 0.0) && (buf[0] != '0'))) {
        sprintf(buf,"Please enter a value in the range [%.2f - %.2f] --> ",min_range,max_range);
        MvWrite(curRowPos,0,buf);
        ret_val = strtod(GetStr(buf), NULL);
    }
    return ret_val;
}

// no bounds checking prior to writing
// base writing routine with no newline added
void CursWin::MvWrite(int r, int c, char* msg, bool ref) {
    mvaddstr(r+upperLeftRow+1,c+upperLeftCol+1,msg);
    curRowPos = r;
    curColPos = c + strlen(msg);
    if (curColPos > maxColPos) {
        curColPos = 0;
        curRowPos++;
    }
    if (ref) refresh();
}

// no bounds checking prior to writing
// base writing routine with newline added
void CursWin::MvWrites(int r, int c, char* msg, bool ref) {
    mvaddstr(r+upperLeftRow+1,c+upperLeftCol+1,msg);
    curRowPos = r+1;
    curColPos = 0;
    if (ref) refresh();
}

void CursWin::Write(char* msg, bool ref) {
    if (curRowPos > (maxRowPos-footerWidth)) {
        ScrollText();
    }    
    MvWrite(curRowPos,curColPos,msg,false);
    if (ref) refresh();
}

void CursWin::Writes(char* msg, bool ref) {
    if (curRowPos > (maxRowPos-footerWidth)) {
        ScrollText();
    }
    MvWrites(curRowPos,curColPos,msg,false);
    if (ref) refresh();
}

void CursWin::MvPutch(int r,int c, char ch, bool ref) {
    curRowPos = r;
    curColPos = c;
    mvaddch(upperLeftRow+1+curRowPos, upperLeftCol+1+curColPos, ch);
    curColPos++;
    if (curColPos > maxColPos) {
        curColPos = 0;
        curRowPos++;
    }
    if (ref) refresh();
}

void CursWin::Putch(char ch, bool ref) {
    if (curRowPos > (maxRowPos-footerWidth)) {
        ScrollText();
    }    
    mvaddch(upperLeftRow+1+curRowPos, upperLeftCol+1+curColPos, ch);
    curColPos++;
    if (curColPos > maxColPos) {
        curColPos = 0;
        curRowPos++;
    }
    if (ref) refresh();
}

// no bounds checking
void CursWin::WriteAsciiImage(int r, int c, FILE* fIn, bool ref) {
    char line[100];
    ClearWin();
    GetLine(line, fIn);
    curRowPos = r;
    curColPos = c;
    while (line[0] != '\0') {
        Writes(line);
        curColPos = c;
        GetLine(line,fIn);
    }
    if (ref) refresh();
}


void CursWin::PlaceWin(int ulr, int ulc, int lrr, int lrc) {
    // if (onScreen) EraseWin(true);
    upperLeftRow = ulr;
    upperLeftCol = ulc;
    lowerRightRow = lrr;
    lowerRightCol = lrc;
    onScreen = true;
    writeEnabled = true;
    DrawBoundingBox('-','|','+');
    ClearWin();
    curRowPos = curColPos = 0;
    headerWidth = footerWidth = 0;
    maxRowPos = lowerRightRow - (upperLeftRow+2);
    maxColPos = lowerRightCol - (upperLeftCol+2);
    sv.expectingStreamParam = false;
    sv.precision = 2;
    sv.left_justified = true;
    sv.last = cflush;
    sv.paramNum = 1;
    sv.field_enabled = false;
    sv.invalid_input = false;
    sv.immErrorHandling = false;
    sv.min_filter = sv.max_filter = sv.fail_value = 0.0;
    sv.force_range = sv.min_active = sv.max_active = false;
    sv.filter_active = 0;
    for (int i = 0; i < 1000; i++) {
        InputStream[i] = '\0';
    }
    isPopUp = false;
    restore = NULL;
}

void CursWin::ShowStream() {
    /*
    bool expectingStreamParam;
    int precision;
    bool left_justified;
    int field_width;
    bool field_enabled;
    CursWinStreamCommand last;
    int paramNum;
    bool invalid_input;
    bool immErrorHandling;
    double min_filter, max_filter;
    bool min_active, max_active;
    bool force_range;
    int filter_active;
    double fail_value;
     */
    CursWin displayWin(0,0,20,79,true);
    const char* TF[2] = {"FALSE","TRUE"};
    char buf[100];
    displayWin << "Current stream: " << InputStream << cnl
               << "Stream values:" << cnl
               << Csetw(4) << " " << "Flags:" << cnl
               << Csetw(8) << " " << "expectingStreamParam: " <<(sv.expectingStreamParam?TF[1]:TF[0]) << cnl
               << Csetw(8) << " " << "left_justified:       " <<(sv.left_justified?TF[1]:TF[0]) << cnl
               << Csetw(8) << " " << "field_enabled:        " <<(sv.field_enabled?TF[1]:TF[0]) << cnl
               << Csetw(8) << " " << "invalid_input:        " <<(sv.invalid_input?TF[1]:TF[0]) << cnl
               << Csetw(8) << " " << "immErrorHandling:     " <<(sv.immErrorHandling?TF[1]:TF[0]) << cnl
               << Csetw(8) << " " << "min_active:           " <<(sv.min_active?TF[1]:TF[0]) << cnl
               << Csetw(8) << " " << "max_active:           " <<(sv.max_active?TF[1]:TF[0]) << cnl
               << Csetw(8) << " " << "force_range:          " <<(sv.force_range?TF[1]:TF[0]) << cnl
               << Csetw(4) << " " << "Numerical values:" << cnl
               << Csetw(8) << " " << "precision:            " << sv.precision << cnl
               << Csetw(8) << " " << "field_width:          " << sv.field_width << cnl
               << Csetw(8) << " " << "paramNum:             " << sv.paramNum << cnl
               << Csetw(8) << " " << "min_filter:           " << sv.min_filter << cnl
               << Csetw(8) << " " << "max_filter:           " << sv.max_filter << cnl
               << Csetw(8) << " " << "filter_active:        " << sv.filter_active << cnl
               << Csetw(8) << " " << "fail_value:           " << sv.fail_value << cnl;
    displayWin.GetStr(buf);
}

// This method writes text to the screen in "paragraph" mode, staying within
// the bounds of the window and scrolling the window upward if necessary
void CursWin::WriteText(char* txt, bool ref) {
    char nextWord[100], *temp = txt;
    char blankWord[2] = "";
    if (((strlen(txt)-1) + curColPos) > maxColPos) {
        temp = GetWord(temp,nextWord);
        if (strlen(nextWord) + curColPos > maxColPos) {
            char* t2 = &(nextWord[0]);
            Writes(blankWord,false);
            while ((*t2 == ' ') || (*t2 == '\n') || (*t2 == '\t')) {
                t2++;
            }
            Write(t2,false);
        }
        else Write(nextWord,false);
        WriteText(temp, false);
    }
    else {
        Write(txt, false);
    }
    if (ref) refresh();
}

char* CursWin::GetToken(char buf[]) {
    int index, start, end;
    char temp[1000];
    char* pos;
    if (InputStream[0] == '\0') GetStr(InputStream);
    pos = &(InputStream[0]);
    index = 0;
    while (InputStream[index] == ' ' || InputStream[index] == '\t') {
        index++;
    }
    start = index;
    while (InputStream[index] != ' '  && 
           InputStream[index] != '\t' && 
           InputStream[index] != '\n' && 
           InputStream[index] != '\0' &&
           InputStream[index] != EOF) {
        buf[index-start] = InputStream[index];
        index++;
    }
    buf[index] = '\0';
    while (InputStream[index] == ' '  ||
           InputStream[index] == '\t' ||
           InputStream[index] == '\n') {
        index++;
    }
    pos = &(InputStream[index]);
    strcpy(temp,pos);
    strcpy(InputStream,temp);
    return &(buf[0]);
}

char CursWin::GetChar() {
    char ret_val;
    char temp[100];
    if (InputStream[0] == '\0') GetStr(InputStream);
    ret_val = InputStream[0];
    if (ret_val == '\0') InputStream[0] = '\0';
    else {
        strcpy(temp,&(InputStream[1]));
        strcpy(InputStream,temp);
    }
    return ret_val;
}


CursWin& operator<<(CursWin &lhs, int rhs) {
    if (!(lhs.sv.expectingStreamParam)) {
        char temp[100];
        sprintf(temp,"%*d",
                (lhs.sv.field_enabled?(lhs.sv.left_justified?-1*lhs.sv.field_width:lhs.sv.field_width):0),
                rhs);
        lhs.WriteText(temp, false);            
        lhs.sv.field_enabled = false;
    }
    else {
        switch (lhs.sv.last.type) {
            case CWSCMINRANGE:
                lhs.sv.min_filter = rhs;
                lhs.sv.min_active = true;
                lhs.sv.filter_active = 1;
                lhs.sv.expectingStreamParam = false;
                break;
            case CWSCMAXRANGE:
                lhs.sv.max_filter = rhs;
                lhs.sv.max_active = true;
                lhs.sv.filter_active = 1;
                lhs.sv.expectingStreamParam = false;
                break;
            case CWSCFILTERLENGTH:
                lhs.sv.filter_active = rhs;
                lhs.sv.expectingStreamParam = false;
                break;
            case CWSCFAILVALUE:
                lhs.sv.fail_value = rhs;
                lhs.sv.expectingStreamParam = false;
                break;
            case CWSCPRECISION:
                lhs.sv.precision = rhs;
                lhs.sv.expectingStreamParam = false;
                break;
            case CWSCFIELDWIDTH:
                lhs.sv.field_enabled = true;
                lhs.sv.field_width = rhs;
                lhs.sv.expectingStreamParam = false;
                break;
            case CWSCPLOTXY:
                if (lhs.sv.paramNum == 1) {                    
                    lhs.curRowPos = rhs;
                }
                else {
                    lhs.curColPos = rhs;
                    lhs.sv.expectingStreamParam = false;
                }
        }
        lhs.sv.paramNum++;
    }
    return lhs;
}

CursWin& operator<<(CursWin &lhs, double rhs) {
    if (lhs.sv.expectingStreamParam) {
        switch (lhs.sv.last.type) {
            case CWSCMINRANGE:
                lhs.sv.min_filter = rhs;
                lhs.sv.min_active = true;
                lhs.sv.filter_active = 1;
                break;
            case CWSCMAXRANGE:
                lhs.sv.max_filter = rhs;
                lhs.sv.max_active = true;
                lhs.sv.filter_active = 1;
                break;
            case CWSCFAILVALUE:
                lhs.sv.fail_value = rhs;
                break;
        }
        lhs.sv.expectingStreamParam = false;
    }
    else {
        char temp[100];
        sprintf(temp,"%*.*f",
                (lhs.sv.field_enabled?(lhs.sv.left_justified?-1*lhs.sv.field_width:lhs.sv.field_width):0),            
                lhs.sv.precision,
                rhs);
        lhs.WriteText(temp, false);
        lhs.sv.field_enabled = false;
    }
    return lhs;
}

CursWin& operator<<(CursWin &lhs, float rhs) {
    if (lhs.sv.expectingStreamParam) {
        switch (lhs.sv.last.type) {
            case CWSCMINRANGE:
                lhs.sv.min_filter = rhs;
                lhs.sv.min_active = true;
                lhs.sv.filter_active = 1;
                break;
            case CWSCMAXRANGE:
                lhs.sv.max_filter = rhs;
                lhs.sv.max_active = true;
                lhs.sv.filter_active = 1;
                break;
            case CWSCFAILVALUE:
                lhs.sv.fail_value = rhs;
                break;
        }
        lhs.sv.expectingStreamParam = false;
    }
    else {
        char temp[100];
        sprintf(temp,"%*.*f",
                (lhs.sv.field_enabled?(lhs.sv.left_justified?-1*lhs.sv.field_width:lhs.sv.field_width):0),            
                lhs.sv.precision,
                rhs);
        lhs.WriteText(temp, false);
        lhs.sv.field_enabled = false;
    }
    return lhs;
}

CursWin& operator<<(CursWin &lhs, char rhs) {
    char temp[2];
    temp[0] = rhs;
    temp[1] = '\0';
    lhs.WriteText(temp, false);
    return lhs;
}

CursWin& operator<<(CursWin &lhs, CursWinStreamCommand rhs) {
    if (rhs.flags & NEWLINE_BIT) {
        lhs.curColPos = 0;
        lhs.curRowPos++;
    }
    if (rhs.flags & REFRESH_BUFFER_BIT) refresh();
    if (rhs.flags & SETPARAM_BIT) {
        lhs.sv.paramNum = 1;
        switch (rhs.type) {
            case CWSCPRECISION:
            case CWSCPLOTXY:
            case CWSCFIELDWIDTH:
            case CWSCMINRANGE:
            case CWSCMAXRANGE:
            case CWSCFAILVALUE:
            case CWSCFILTERLENGTH:
                lhs.sv.expectingStreamParam = true;
                break;
            case CWSCLEFTJUSTIFY:
                lhs.sv.left_justified = true;
                break;
            case CWSCRIGHTJUSTIFY:
                lhs.sv.left_justified = false;
                break;
        }
    }
    if (rhs.flags & CLEARWIN_BIT) {
        lhs.ClearWin();
    }
    if (rhs.flags & TOGGLE_FLAG_BIT) {
        switch (rhs.type) {
            case CWSCTOGSCROLL:
                lhs.scrolling = false;
        }
    }
    lhs.sv.last = rhs;
    return lhs;
}

CursWin& operator<<(CursWin &lhs, char* rhs) {
    if (!strlen(rhs)) return lhs;
    if (!(lhs.sv.field_enabled)) lhs.WriteText(rhs, false);
    else {
        char temp[100];
        sprintf(temp,"%*s",
            (lhs.sv.left_justified?-1*lhs.sv.field_width:lhs.sv.field_width),            
             rhs);
        lhs.WriteText(temp,false);
        lhs.sv.field_enabled = false;
    }
    return lhs;
}


CursWin& operator<<(CursWin &lhs, const char* rhs) {
    if (!strlen(rhs)) return lhs;
    char msg[100];
    strcpy(msg,rhs);
    if (!(lhs.sv.field_enabled)) lhs.WriteText(msg, false);
    else {
        char temp[100];
        sprintf(temp,"%*s",
            (lhs.sv.left_justified?-1*lhs.sv.field_width:lhs.sv.field_width),            
             rhs);
        lhs.WriteText(temp,false);
        lhs.sv.field_enabled = false;
    }
    return lhs;
}

CursWin& operator<<(CursWin &lhs, std::string &rhs) {
    if (!rhs.length()) return lhs;
    if (!(lhs.sv.field_enabled)) lhs.WriteText((char*)(rhs.c_str()), false);
    else {
        char temp[100];
        sprintf(temp,"%*s",
            (lhs.sv.left_justified?-1*lhs.sv.field_width:lhs.sv.field_width),            
             rhs.c_str());
        lhs.WriteText(temp,false);
        lhs.sv.field_enabled = false;
    }
    return lhs;
}



CursWin& operator>>(CursWin &lhs, char rhs[]) {
    if (lhs.sv.invalid_input) {
        lhs.InputStream[0] = '\0';
        lhs.sv.invalid_input = false;
    }
   lhs.GetToken(rhs);
    return lhs;
}

CursWin& operator>>(CursWin &lhs, std::string &rhs) {
    char token[100];
    if (lhs.sv.invalid_input) {
        lhs.InputStream[0] = '\0';
        lhs.sv.invalid_input = false;
    }
    lhs.GetToken(token);
    rhs = token;
    return lhs;
}

CursWin& operator>>(CursWin &lhs, char &rhs) {
    if (lhs.sv.invalid_input) {
        lhs.InputStream[0] = '\0';
        lhs.sv.invalid_input = false;
    }
    rhs = lhs.GetChar();
    return lhs;
}

CursWin& operator>>(CursWin &lhs, int &rhs) {
    if (lhs.CursErrorOut != NULL) {
        *(lhs.CursErrorOut) << "Inside " << lhs.windowName << " >> <int> function call..." << cendl;
    }
    if (lhs.sv.invalid_input) {
        lhs.InputStream[0] = '\0';
        lhs.sv.invalid_input = false;
    }
    char temp[1000];
    char errorWinName[10] = "errorWin";
    int tval = rhs;
    lhs.GetToken(temp);
    rhs = atoi(temp);
    if ((rhs == 0) && (temp[0] != '0')) {
        rhs = tval;
        lhs.sv.invalid_input = true;
        if (lhs.sv.immErrorHandling) lhs.HandleInputError(EXPECTED_INT);
    }
    else if (lhs.sv.filter_active) {
//        *(lhs.CursErrorOut) << "Filtering value... " << cendl;
        if ((lhs.sv.min_active && (rhs < lhs.sv.min_filter)) ||
            (lhs.sv.max_active && (rhs > lhs.sv.max_filter))) {
//            *(lhs.CursErrorOut) << "Value out of range..." << cendl;
            if (lhs.sv.force_range) {
//                *(lhs.CursErrorOut) << "Forcing value within range..." << cendl;
//                *(lhs.CursErrorOut) << "Creating error window..." << cendl;
                CursWin errorWin(lhs.upperLeftRow+(lhs.curRowPos-1),lhs.upperLeftCol,lhs.upperLeftRow + lhs.curRowPos+1,lhs.lowerRightCol,true);
//                *(lhs.CursErrorOut) << "Window created, continuing..." << cendl;
                errorWin.SetName(errorWinName);
                errorWin.SetErrorOutput(lhs.CursErrorOut);
                errorWin << " " << rhs << " is out of range. Enter a value [";
                if (lhs.sv.min_active) {
                    errorWin << csetmin << lhs.sv.min_filter;
                    errorWin << lhs.sv.min_filter;
                }
                else {
                    errorWin << "-inf";
                }
                errorWin << " - ";                    
                if (lhs.sv.max_active) {
                    errorWin << csetmax << lhs.sv.max_filter;
                    errorWin << lhs.sv.max_filter;
                }
                else {
                    errorWin << "inf";
                }
                errorWin << "] --> " << cflush;
                errorWin >> cforce >> rhs;
            }
            else rhs = (int)(lhs.sv.fail_value);
        }
        lhs.sv.filter_active--;
    }
    return lhs;
}

CursWin& operator>>(CursWin &lhs, double &rhs) {
    if (lhs.sv.invalid_input) {
        lhs.InputStream[0] = '\0';
        lhs.sv.invalid_input = false;
    }
    char temp[1000];
    double tval = rhs;
    lhs.GetToken(temp);
    rhs = strtod(temp, NULL);
    if ((rhs == 0.0) && (temp[0] != '0')) {
        rhs = tval;
        lhs.sv.invalid_input = true;
        if (lhs.sv.immErrorHandling) lhs.HandleInputError(EXPECTED_FLOAT);
    }
    else if (lhs.sv.filter_active) {
        if ((lhs.sv.min_active && (rhs < lhs.sv.min_filter)) ||
            (lhs.sv.max_active && (rhs > lhs.sv.max_filter))) {
            if (lhs.sv.force_range) {
                CursWin errorWin(lhs.upperLeftRow+(lhs.curRowPos-1),lhs.upperLeftCol,lhs.curRowPos+1,lhs.lowerRightCol,true);
                errorWin << " " << rhs << " is out of range. Enter a value [";
                if (lhs.sv.min_active) {
                    errorWin << csetmin << lhs.sv.min_filter;
                    errorWin << lhs.sv.min_filter;
                }
                else {
                    errorWin << "-inf";
                }
                errorWin << " - ";                    
                if (lhs.sv.max_active) {
                    errorWin << csetmax << lhs.sv.max_filter;
                    errorWin << lhs.sv.max_filter;
                }
                else {
                    errorWin << "inf";
                }
                errorWin << "] --> " << cflush;
                errorWin >> cforce >> rhs;
            }
            else rhs = lhs.sv.fail_value;
        }
        lhs.sv.filter_active--;
    }
    return lhs;
}

CursWin& operator>>(CursWin &lhs, float &rhs) {
    if (lhs.sv.invalid_input) {
        lhs.InputStream[0] = '\0';
        lhs.sv.invalid_input = false;
    }
    char temp[1000];
    double tval = rhs;
    lhs.GetToken(temp);
    rhs = atof(temp);
    if ((rhs == 0.0) && (temp[0] != '0')) {
        rhs = tval;
        lhs.sv.invalid_input = true;
        if (lhs.sv.immErrorHandling) lhs.HandleInputError(EXPECTED_FLOAT);
    }
    else if (lhs.sv.filter_active) {
        if ((lhs.sv.min_active && (rhs < lhs.sv.min_filter)) ||
            (lhs.sv.max_active && (rhs > lhs.sv.max_filter))) {
            if (lhs.sv.force_range) {
                CursWin errorWin(lhs.upperLeftRow+(lhs.curRowPos-1),lhs.upperLeftCol,lhs.curRowPos+1,lhs.lowerRightCol,true);
                errorWin << " " << rhs << " is out of range. Enter a value [";
                if (lhs.sv.min_active) {
                    errorWin << csetmin << lhs.sv.min_filter;
                    errorWin << lhs.sv.min_filter;
                }
                else {
                    errorWin << "-inf";
                }
                errorWin << " - ";                    
                if (lhs.sv.max_active) {
                    errorWin << csetmax << lhs.sv.max_filter;
                    errorWin << lhs.sv.max_filter;
                }
                else {
                    errorWin << "inf";
                }
                errorWin << "] --> " << cflush;
                errorWin >> cforce >> rhs;
            }
            else rhs = (float)(lhs.sv.fail_value);
        }
        lhs.sv.filter_active--;
    }
    return lhs;
}


CursWin& operator>>(CursWin &lhs, CursWinStreamCommand rhs) {
    if (rhs.flags & SETPARAM_BIT) {
        lhs.sv.paramNum = 1;
        switch (rhs.type) {
            case CWSCPRECISION:
            case CWSCPLOTXY:
            case CWSCFIELDWIDTH:
            case CWSCMINRANGE:
            case CWSCMAXRANGE:
            case CWSCFAILVALUE:
            case CWSCFILTERLENGTH:
                lhs.sv.expectingStreamParam = true;
                break;
        }
    }
    if (rhs.flags & TOGGLE_FLAG_BIT) {
        switch (rhs.type) {
            case CWSCRESETFLAGS:
                lhs.sv.invalid_input = false;
                break;
            case CWSCTOGGLEIMMERR:
                lhs.sv.immErrorHandling = !lhs.sv.immErrorHandling;
                break;
            case CWSCFORCERANGE:
                lhs.sv.force_range = !lhs.sv.force_range;
                break;
        }
    }
    lhs.sv.last = rhs;
    return lhs;
}

char* GetLine(char buf[], FILE* fIn) {
    int pos = 0;
    char inch = fgetc(fIn);
    while ((inch != '\n') && (inch != EOF)) {
        buf[pos++] = inch;
        inch = fgetc(fIn);
    }
    buf[pos] = '\0';
    return &(buf[0]);
            
}

char* GetWord(char src[], char buf[]){
    int index = 0;
    while ((src[index] == ' ') || (src[index] == '\n') || (src[index] == '\t')) {
        if (src[index] == '\t') buf[index] = '\t';
        else buf[index] = ' ';
        index++;
    }
    while ((src[index] != ' ') && (src[index] != '\n') && (src[index] != EOF) && (src[index] != '\t') && (src[index] != '\0')) {
        buf[index] = src[index];
        index++;
    }
    buf[index] = '\0';
    return &(src[index]);
}
