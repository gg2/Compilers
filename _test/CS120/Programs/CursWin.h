/* 
 * File:   CursWin.h
 * Author: Joshua Rubini
 *
 * Created on June 4, 2012, 10:15 AM
 */

#ifndef CURSWIN_H
#define	CURSWIN_H
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>

#include <curses.h>

char* GetLine(char buf[], FILE* fIn = stdin);
char* GetWord(char src[], char buf[]);

typedef struct _CWSC {
    int flags;
    int type;
    
    _CWSC& operator=(_CWSC rhs) {flags = rhs.flags; type = rhs.type; return *this;}
} CursWinStreamCommand;

// Error handling constants

const int EXPECTED_INT = 0;
const int EXPECTED_FLOAT = 1;

// CWSC flags

const int REFRESH_BUFFER_BIT = 1;
const int NEWLINE_BIT = 2;
const int SETPARAM_BIT = 4;
const int CLEARWIN_BIT = 8;
const int TOGGLE_FLAG_BIT = 16;
const int CWSCPRECISION = 0;
const int CWSCFIELDWIDTH = 1;
const int CWSCLEFTJUSTIFY = 2;
const int CWSCRIGHTJUSTIFY = 3;
const int CWSCMINRANGE = 4;
const int CWSCMAXRANGE = 5;
const int CWSCFILTERLENGTH = 6;
const int CWSCPLOTXY = 7;
const int CWSCFAILVALUE = 8;
const int CWSCTOGSCROLL = 0;
const int CWSCRESETFLAGS = 1;
const int CWSCTOGGLEIMMERR = 2;
const int CWSCFORCERANGE = 3;

// stream command constants
// TODO: Create an input from window stream command
const CursWinStreamCommand cendl = {3,0};
const CursWinStreamCommand cnl = {2,0};
const CursWinStreamCommand cflush = {1,0};
const CursWinStreamCommand csetprecision = {4,CWSCPRECISION};
const CursWinStreamCommand csetw = {4,CWSCFIELDWIDTH};
const CursWinStreamCommand cleft = {4,CWSCLEFTJUSTIFY};
const CursWinStreamCommand cright = {4,CWSCRIGHTJUSTIFY};
const CursWinStreamCommand cclr = {8,0};
const CursWinStreamCommand cmove = {4,CWSCPLOTXY};
const CursWinStreamCommand cnoscroll = {16,CWSCTOGSCROLL};
const CursWinStreamCommand creset = {16,CWSCRESETFLAGS};
const CursWinStreamCommand ctogerr = {16,CWSCTOGGLEIMMERR};
const CursWinStreamCommand csetmin = {4,CWSCMINRANGE};
const CursWinStreamCommand csetmax = {4,CWSCMAXRANGE};
const CursWinStreamCommand cfiltersize = {4,CWSCFILTERLENGTH};
const CursWinStreamCommand cforce = {16,CWSCFORCERANGE};
const CursWinStreamCommand cdefval = {4,CWSCFAILVALUE};

// Macro definitions

#define Csetw(x) csetw << x
#define Csetprecision(x) csetprecision << x
#define Cmove(r,c) cmove << r << c
#define Cplot(r,c,out) Cmove(r,c) << out
#define Cget(r,c,in) Cmove(r,c) >> in
#define Cfilter(min,max) csetmin << min << csetmax << max
#define Cfilterfv(min,max,fail) Cfilter(min,max) << cdefval << fail
#define Cfiltern(min,max,n) Cfilter(min,max) << cfiltersize << n
#define Cfilternfv(min,max,n,fail) Cfiltern(min,max,n) << cdefval << fail

typedef struct _sv {
    bool expectingStreamParam;
    bool left_justified;
    bool field_enabled;
    bool invalid_input;
    bool immErrorHandling;
    bool min_active, max_active;
    bool force_range;

    int precision;
    int field_width;
    int paramNum;
    double min_filter, max_filter;
    int filter_active;
    double fail_value;

    CursWinStreamCommand last;
} StreamValue;

class CursWin {
public:
    /***************************************************************************
     * Constructors/Destructor
     * 
     * CursWin(void)
     *    Allows definition of a basic CursWin object with no parameters.
     *    Window will not appear on screen and is not writable.  Must use
     *    PlaceWin(int,int,int,int) to place the window on the screen prior
     *    to using.
     * 
     * CursWin(int ulr, int ulc, int lrr, int lrc, bool Pop = false)
     *    Defines a CursWin with upper left corner at (ulr,ulc) on the screen,
     *    and lower right corner at (lrr,lrc).  Uses default border characters
     *    -, |, and +.  If Pop is true, this window is a "pop-up" window and it
     *    assumes it is covering another window on the screen, so it sets up
     *    the restore array with whatever was on the screen before it is drawn.
     * 
     * CursWin(int, int, int, int, char horiz, char vert, char corner)
     *    Same as CursWin(int,int,int,int,bool) but defines a custom border.
     *    May not be used as a pop-up window.
     * 
     * ~CursWin(void)
     *    frees the restore array if allocated
     * 
     * Default values for class:
     *     writeEnabled = true; (false if base constructor is used)
     *     scrolling = true;
     *     onScreen = true;     (false if base constructor is used)
     *     curRowPos = curColPos = 0;
     *     maxRowPos = lowerRightRow - (upperLeftRow+2);
     *     maxColPos = lowerRightCol - (upperLeftCol+2);
     *     sv.expectingStreamParam = false;
     *     sv.precision = 2;
     *     sv.left_justified = true;
     *     sv.last = cflush;
     *     sv.field_enabled = false;
     *     sv.paramNum = 1;
     *     sv.invalid_input = false;
     *     sv.immErrorHandling = false;
     *     sv.min_filter = sv.max_filter = sv.fail_value = 0.0;
     *     sv.force_range = sv.min_active = sv.max_active = false;
     *     sv.filter_active = 0;
     * 
     **************************************************************************/
    CursWin();
    CursWin(int, int, int, int, bool Pop = false);
    CursWin(int, int, int, int, char, char, char);
    virtual ~CursWin();
        
    /***************************************************************************
     * Output/writing methods:
     * 
     * NOTE:  All writing methods have a default boolean parameter ref which
     * determines whether or not the screen is refreshed at the end of the
     * method.  The default value is true, but if you are writing many things
     * to the screen you may want to set it to false to avoid flicker.
     * 
     * void MvWrite(int r, int c, char* msg, bool ref = true)
     *    Basic writing method.  Most other writing methods call either this
     *    method or MvWrites().  Moves the current row and column to (r,c) and
     *    writes msg into the window at this location.  Updates column position
     *    based upon string length, but keeps same row position, unless new
     *    column position is past the maximum column position for the window, in
     *    which case it moves to the next row and column 0.
     * 
     *    ### IMPORTANT NOTE: This method _does not_ check to make sure the
     *    ###                 message fits within the window!  Use WriteText()
     *    ###                 instead
     * 
     * void MvWrites(int r, int c, char* msg, bool ref = true)
     *    Basic writing method.  Most other writing methods call either this
     *    method or MvWrites().  Moves the current row and column to (r,c) and
     *    writes msg into the window at this location.  Moves the current row to
     *    the next row, and the current column to 0, which is effectively
     *    equivalent to writing a newline character
     * 
     *    ### IMPORTANT NOTE: This method _does not_ check to make sure the
     *    ###                 message fits within the window!  Use WriteText()
     *    ###                 instead
     * 
     * void MvPutch(int r, int c, char ch, bool ref = true)
     *    Basic writing method.  Other single character writing methods call
     *    this method.  Moves the current row and column to (r,c) and places ch
     *    at that location.
     * 
     *    ### IMPORTANT NOTE: This method _does not_ check to make sure the
     *    ###                 message fits within the window!  Use WriteText()
     *    ###                 instead
     * 
     * void Write(char* msg, bool ref = true)
     *    Writing method which calls MvWrite(curRowPos, curColPos, msg, false)
     *    Writes the message to the current location in the window, and does
     *    not append a newline unless the updated column position is past the
     *    maximum allowed column position
     * 
     * void Writes(char* msg, bool ref = true)
     *    Writing method which calls MvWrites(curRowPos, curColPos, msg, false)
     *    Writes the message to the current location in the window, and adds
     *    a newline at the end.
     * 
     * void Putch(char ch, bool ref = true)
     *    Writing method which calls MvPutch(curRowPos, curColPos, ch, false)
     *    Writes the character to the current location in the window, and does
     *    not append a newline unless the updated column position is past the
     *    maximum allowed column position
     * 
     * void WriteAsciiImage(int r, int c, FILE* fIn, bool ref = true)
     *    This method "draws" an ascii image to a window location.  It first
     *    clears the window using ClearWin(), then moves the current row and
     *    column to (r,c).  It then writes a line at a time to the window from
     *    the file using Writes().  The file must be opened and closed 
     *    separately
     * 
     * void WriteText(char* txt, bool ref = true) ***RECURSIVE***
     *    This is the main writing method intended for use.  This method writes
     *    the text in the string to the window, but first checks to make sure
     *    the string will not exceed the length of the window.  If it does, it
     *    strips off a token from the string, checks to see if that token will
     *    fit, and if so writes it to the window and then strips another token
     *    and repeats.  If the token will not fit, it moves to the next line,
     *    and then continues writing the remaining text recursively.  It also
     *    properly removes leading whitespace from the first token on the line.
     * 
     **************************************************************************/
    
    void MvWrite(int, int, char*, bool ref = true);
    void MvWrites(int,int,char*,bool ref = true);
    void MvPutch(int,int,char, bool ref = true);
    void Write(char*, bool ref = true);
    void Writes(char*, bool ref = true);
    void Putch(char, bool ref = true);
    void WriteAsciiImage(int,int,FILE*,bool ref = true);
    void WriteText(char* txt, bool ref = true);
    
    /***************************************************************************
     * Input methods:
     * 
     * *** NOTE: These are not stream input methods, these are functions ***
     * 
     * char* GetStr(char buf[])
     *    Gets a line of text from the input device, and stores it in buf[].
     *    returns a pointer to the first character in the string.
     *    NOTE: This is the main input method used by the stream operator >>
     * 
     * int GetInt(int min, int max)
     *    Gets an integer from the input device, constrained by the min and max
     *    values.  Returns the integer
     * 
     * double GetDouble(double min, double max)
     *    Gets a double precision value from the input device, constrained by
     *    the min and max values.  Returns the double
     * 
     * char MvGetChar(int r, int c)
     *    finds the character in the window at location (r,c) and returns it
     * 
     **************************************************************************/
    
    char* GetStr(char []);
    int GetInt(int min, int max);
    double GetDouble(double min, double max);
    char MvGetChar(int r, int c) {return mvinch(r+upperLeftRow+1, c+upperLeftCol+1);}

    /***************************************************************************
     * Auxiliary methods:
     * 
     * void ClearWin(void):
     *    Clears the window, and sets current row and column to 0
     * 
     * void PlaceWin(int ulr,int ulc,int lrr,int lrc):
     *    Places the window with upper left corner of (ulr, ulc) and
     *    lower right corner of (lrr, lrc).  Makes window visible and writable
     * 
     * bool isWritable(void):
     *    returns the writeEnabled flag
     * 
     * bool isVisible(void):
     *    returns the onScreen flag
     * 
     * void WriteProtect(void):
     *    toggles the writeEnabled flag
     * 
     * void Hide(void):
     *    **** under construction ****
     *    currently erases the window, and sets onScreen to false
     *    TODO: implement window memory and Show() method
     * 
     * char* GetStream(void):
     *    returns the current input stream buffer
     * 
     * bool Fail(void)
     *    returns the stream value structure invalid_input flag
     * 
     * void Move(int r, int c)
     *    sets the current row and column position to (r,c)
     * 
     * void ShowStream(void)
     *    creates a popup window showing the current stream value parameters
     * 
     * void SetErrorOutput(CursWin *c)
     *    Links this window to another for error reporting.  Used for debugging
     * 
     * void SetName(char *n)
     *    Used to create an internal label for this window.  Used for debugging
     ***************************************************************************/
    
    void ClearWin() {for (int y = upperLeftRow+headerWidth+1; y < (lowerRightRow-footerWidth); y++) for (int x = upperLeftCol+1; x < lowerRightCol; x++) mvaddch(y,x,' '); curRowPos = headerWidth; curColPos = 0;}
    void PlaceWin(int,int,int,int);
    bool isWritable() {return writeEnabled;}
    bool isVisible() {return onScreen;}
    void WriteProtect() {writeEnabled = !writeEnabled;};
    void Hide() {EraseWin(); onScreen = false;}
    char* GetStream() {return &(InputStream[0]);}
    bool Fail() {return sv.invalid_input;}
    void Move(int r, int c) {curRowPos = r; curColPos = c;};
    void ShowStream();
    void SetErrorOutput(CursWin *c) {CursErrorOut = c;}
    void SetName(char *n) {strcpy(windowName,n);}
    CursWin* GetErrorOut() {return CursErrorOut;}
    void SetHeader(int n) {headerWidth = n;}
    void SetFooter(int n) {footerWidth = n;}
    static int GetNumberOfWindows() {return numWindows;}
    
    // Stream operator overloads:
    /***************************************************************************
     * Output stream operator overloads:
     * 
     * General notes:
     *    These methods generally use sprintf() to convert the right hand
     *    operand to a c-style string if it is not one already, and then
     *    WriteText() to write it to the window.  It supports standard output
     *    stream commands such as setting field width, justification, precision,
     *    etc.  Here is a detailed list of the supported types and output
     *    commands:
     * 
     * Right hand operator types:
     *    int, float, double, char, const char*, char*, CursWinStreamCommand
     * 
     * CursWinStreamCommands:
     *    cflush:
     *       Causes the screen to refresh (similar to flush for iostream)
     *    cnl:
     *       Moves to the next row, and column 0 (similar to "\n")
     *    cendl:
     *       cnl + cflush
     *    cleft/cright:
     *       sets the justification within the field to left (default) or right
     *    csetw:
     *       This command sets the field width.  The stream expects an integer
     *       to follow this command and will use it as the field width value.
     *       This is not persistent; it only sets this field width for a single
     *       output value (similar to setw).
     *       Ex: for (int i =1; i <= 10; i++) 
     *              myWin << cright << csetw << 5 << i << cendl;
     *       output:
     *           1:
     *           2:
     *           3:
     *           4:
     *           5:
     *           6:
     *           7:
     *           8:
     *           9:
     *          10:
     *    csetprecision:
     *       This command sets the floating point precision for any floating
     *       point values written to the stream.  It expects an integer to
     *       follow this command which is the number of decimal places to write.
     *       This value is persistent and is in place until the next
     *       csetprecision command (similar to setprecision) 
     *    cclr:
     *       This command clears the current window and moves the current row
     *       and column to (0,0) (using the ClearWin() method)
     *    cnoscroll:
     *       This command disables scrolling within the current window.
     *    cmove:
     *       This command moves the current row and column.  It expects to be
     *       followed by 2 integers (ie: win << cmove << 2 << 2), the first
     *       of which is the new row, and the second is the new column
     *    
     * Input stream commands that use the output operator:
     * Due to limitations on overloading, certain input stream commands must be
     * used with the output stream operator.  These are:
     * 
     *    csetmin:
     *       This command sets the minimum value to be input, activates the
     *       minimum filter, and sets the number of values to be filtered to 1.
     *       It expects to be followed by a single integer.
     *       (ie: win << csetmin << 5.0; win >> inValue; //value must be >= 5.0)
     *    csetmax:
     *       Same as csetmin but sets the maximum value
     *    cfiltersize:
     *       Sets the number of values to be actively filtered.
     *    cdefval:
     *       Sets the value to be returned if the input value is outside the
     *       allowed range. 
     *
     * Input stream commands that use the input operator:
     * 
     *    ctogerr:
     *       This command toggles immediate error handling on or off for
     *       input type mismatches (ie, your program is expecting an integer
     *       input and gets a string).  If immediate error handling is on, then
     *       an error window will pop up asking you if you would like to either
     *       reset the stream or exit the program.  If it is off, a type
     *       mismatch causes the invalid_input flag to be set, which can be
     *       detected using the Fail() method.
     * 
     *    creset:
     *       Sets the invalid_input flag to false and the first character in
     *       the input stream to null (to force getting new input on the
     *       next input request).
     * 
     *    cforce: <toggle>
     *       This command toggles forced input validation on or off.  Forced 
     *       input validation requires input to fall between minimum and maximum
     *       values.  Entering a value outside the range will cause an error
     *       window to pop up, requesting a new value.  Any values still
     *       on the input stream of the original window are unaffected.
     *
     *       If forced input validation is off, any values that fall outside the
     *       allowable range are set to the fail_value field of the stream.
     *
     *       Example:
     *       CursWin inWin(0,0,20,79);
     *       int in1, in2, in3;
     *       inWin << "Please enter 3 integers in the range [5-20] --> ";
     *       inWin << csetmin << 5 << csetmax << 20 << cfiltersize << 3;
     *       inWin >> cforce >> in1 >> in2 >> in3;
     * 
     *       if the user entered: "6 31 14" as input, it would accept the 6,
     *       then reject the 31 and ask for new input in a new window.  Once the
     *       user enters good input, it returns to the original window, and the 
     *       14 is still sitting in the input stream and is accepted. 
     * 
     * Macro definitions:
     * 
     *   Csetw(x):                      csetw << x
     *   Csetprecision(x):              csetprecision << x
     *   Cmove(r,c):                    cmove << r << c
     *   Cplot(r,c,out):                Cmove(r,c) << out
     *   Cget(r,c,in):                  Cmove(r,c) >> in
     *   Cfilter(min,max)               csetmin << min << csetmax << max
     *   Cfilterfv(min,max,fail)        Cfilter(min,max) << cdefval << fail
     *   Cfiltern(min,max,n)            Cfilter(min,max) << cfiltersize << n
     *   Cfilternfv(min,max,n,fail)     Cfiltern(min,max,n) << cdefval << fail   
     * 
     **************************************************************************/
    
    // output
    friend CursWin& operator<<(CursWin &lhs, int rhs);                 
    friend CursWin& operator<<(CursWin &lhs, double rhs);
    friend CursWin& operator<<(CursWin &lhs, float rhs);
    friend CursWin& operator<<(CursWin &lhs, char rhs);
    friend CursWin& operator<<(CursWin &lhs, CursWinStreamCommand rhs);
    friend CursWin& operator<<(CursWin &lhs, char* rhs);
    friend CursWin& operator<<(CursWin &lhs, const char* rhs);
    friend CursWin& operator<<(CursWin &lhs, std::string &rhs);
    
    // input
    friend CursWin& operator>>(CursWin &lhs, char rhs[]);
    friend CursWin& operator>>(CursWin &lhs, char &rhs);
    friend CursWin& operator>>(CursWin &lhs, int &rhs);
    friend CursWin& operator>>(CursWin &lhs, double &rhs);
    friend CursWin& operator>>(CursWin &lhs, float &rhs);
    friend CursWin& operator>>(CursWin &lhs, CursWinStreamCommand rhs);    
    friend CursWin& operator>>(CursWin &lhs, std::string &rhs);
    
protected:
    int upperLeftRow, upperLeftCol, lowerRightRow, lowerRightCol;
    int maxRowPos, maxColPos, curRowPos, curColPos, headerWidth, footerWidth;
    bool writeEnabled, onScreen, scrolling, isPopUp;
    char InputStream[1000];
    char **restore;
    StreamValue sv;
    void DrawBoundingBox(char, char, char);
    void EraseWin(bool ref = true);
    char* GetToken(char []);
    void ScrollText();
    void HandleInputError(int expectedType);
    char GetChar();
    CursWin* CursErrorOut;
    char windowName[10];
    static int numWindows;
};

class CursPlotWin: public CursWin {
public:
    CursPlotWin();
    ~CursPlotWin();
protected:
    double y_min,y_max;
    double x_min,x_max;
};


#endif	/* CURSWIN_H */
