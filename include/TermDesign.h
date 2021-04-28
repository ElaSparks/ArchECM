#ifndef MYTERM_H
#define MYTERM_H
#include <iostream>
#include <sys/ioctl.h>
#include <termios.h>

/**
 * Color enumeration to personalize some parts of the UI
 */
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

/**
 * A small class for personalizing the terminal: changing colors, clearing the
 * screen, receiving metadata.
 */
class TermDesign {
protected:
    void cleanScreen();
    int move(int rows, int cols);
    int getScreenSize(int& rows, int& cols);
    void setScreenSize(int rows, int cols);
    void setForegroundColor(colors color);
    void setBackgroundColor(colors color);
};

#endif
