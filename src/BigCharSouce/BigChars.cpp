#include "../../include/BigChars.h"
/**
 * Outputs a character string using an optional encoding table
 * @file BigChars.cpp
 * @param str - the string to be encoded in ASC
 */
void BigChars::printASC(const std::string& str)
{
    printf("\E(0%s\E(B", str.c_str());
}
int BigChars::printFrame(int x, int y, int height, int width)
{
    if (!((x > 0 && y > 0) && (height > 1 && width > 1))) {
        return -1;
    }
    height--;
    width--;
    move(x, y);
    printASC("l");
    move(x + height, y);
    printASC("m");
    move(x, y + width);
    printASC("k");
    move(x + height, y + width);
    printASC("j");
    for (int i = 1; i < width; ++i) {
        move(x, y + i);
        printASC("q");
        move(x + height, y + i);
        printASC("q");
    }
    for (int i = 1; i < height; ++i) {
        move(x + i, y);
        printASC("x");
        move(x + i, y + width);
        printASC("x");
    }
    return 0;
}
int BigChars::printBigChar(
        unsigned long long symbol,
        int x,
        int y,
        colors color,
        colors backgroundColor)
{
    int windowRows = 0, windowCols = 0;
    getScreenSize(windowRows, windowCols);
    if (!((x < windowRows) && (y < windowCols) && (x > 0 && y > 0))) {
        return -1;
    }
    setForegroundColor(color);
    setBackgroundColor(backgroundColor);
    for (int i = 0; i < 8; i++) {
        move(x + i, y);
        for (int j = 0; j < 8; j++) {
            if ((symbol & 1)) {
                printASC("a");
            } else {
                printf(" ");
            }
            symbol = symbol >> 1;
        }
    }
    setForegroundColor(Reset);
    setBackgroundColor(Reset);
    return 0;
}
