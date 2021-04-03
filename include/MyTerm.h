#ifndef MYTERM_H
#define MYTERM_H
#include <iostream>
#include <sys/ioctl.h>
#include <termios.h>

enum colors {
    Black,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White,
    Reset = 9
};

class MyTerm {
protected:
    void mt_clrscr();
    int mt_gotoXY(int rows, int cols);
    int mt_getscreensize(int& rows, int& cols);
    void mt_setscreensize(int rows, int cols);
    void mt_setfgcolor(colors color);
    void mt_setbgcolor(colors color);
};

#endif
