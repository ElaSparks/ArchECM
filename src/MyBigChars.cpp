#include "../include/MyBigChars.h"
void MyBigChars::bc_printA(const std::string& str)
{
    printf("\E(0%s\E(B", str.c_str());
}
int MyBigChars::bc_box(int x, int y, int height, int width)
{
    if (!((x > 0 && y > 0) && (height > 1 && width > 1))) {
        return -1;
    }
    height--;
    width--;
    mt_gotoXY(x, y);
    bc_printA("l");
    mt_gotoXY(x + height, y);
    bc_printA("m");
    mt_gotoXY(x, y + width);
    bc_printA("k");
    mt_gotoXY(x + height, y + width);
    bc_printA("j");
    for (int i = 1; i < width; ++i) {
        mt_gotoXY(x, y + i);
        bc_printA("q");
        mt_gotoXY(x + height, y + i);
        bc_printA("q");
    }
    for (int i = 1; i < height; ++i) {
        mt_gotoXY(x + i, y);
        bc_printA("x");
        mt_gotoXY(x + i, y + width);
        bc_printA("x");
    }
    return 0;
}
int MyBigChars::bc_printbigchar(
        unsigned long long symbol,
        int x,
        int y,
        colors color,
        colors backgroundColor)
{
    int windowRows = 0, windowCols = 0;
    mt_getscreensize(windowRows, windowCols);
    if (!((x < windowRows) && (y < windowCols) && (x > 0 && y > 0))) {
        return -1;
    }
    mt_setfgcolor(color);
    mt_setbgcolor(backgroundColor);
    for (int i = 0; i < 8; i++) {
        mt_gotoXY(x + i, y);
        for (int j = 0; j < 8; j++) {
            if ((symbol & 1)) {
                bc_printA("a");
            } else {
                std::cout << " ";
            }
            symbol = symbol >> 1;
        }
    }
    mt_setfgcolor(Reset);
    mt_setbgcolor(Reset);
    return 0;
}
