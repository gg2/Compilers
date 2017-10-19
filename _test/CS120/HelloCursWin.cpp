#include"CursWin.h"

int main() {
	CursWin outw(0,0,40,20);
	CursWin inw(40,20,50,27);
	outw << "Hello, world!" << cendl;
	outw << Cmove(20,10) << "This is @ the center of the screen." << cendl;
//	outw << cflush;

	int x;
	inw >> x;
	outw << Cmove(2,2) << x;
	
	inw >> x;
	return 0;
}