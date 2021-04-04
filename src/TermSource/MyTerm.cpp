#include "../../include/MyTerm.h"
void MyTerm::mt_clrscr()
{
    printf("\033c");
}
int MyTerm::mt_gotoXY(int rows, int cols)
{
    if (rows < 0 || cols < 0) {
        return -1;
    }
    printf("\E[%d;%dH", rows, cols);
    return 0;
}
int MyTerm::mt_getscreensize(int& rows, int& cols)
{
    winsize windowSizePair{};
    if (ioctl(1, TIOCGWINSZ, &windowSizePair)) {
        return -1;
    }
    rows = windowSizePair.ws_row;
    cols = windowSizePair.ws_col;
    return 0;
}
void MyTerm::mt_setscreensize(int rows, int cols)
{
    printf("\E[8;%d;%d;t", rows, cols);
}
void MyTerm::mt_setfgcolor(colors color)
{
    printf("\E[3%dm", color);
}
void MyTerm::mt_setbgcolor(colors color)
{
    printf("\E[4%dm", color);
}
