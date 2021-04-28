#include "../../include/TermDesign.h"
/**
 * The function returns the parameters of the terminal size
 * @file TermScreenSize.cpp
 * @param rows - a variable into which the reference will return a value
 * indicating the number of rows
 * @param cols - a variable into which the reference will return a value
 * indicating the number of columns
 * @return Operation result
 */
int TermDesign::getScreenSize(int& rows, int& cols)
{
    winsize windowSizePair{};
    if (ioctl(1, TIOCGWINSZ, &windowSizePair)) {
        return -1;
    }
    rows = windowSizePair.ws_row;
    cols = windowSizePair.ws_col;
    return 0;
}
/**
 * The function sets specific parameters of the terminal size.
 * @file TermScreenSize.cpp
 * @param rows - number of rows
 * @param cols - number of columns
 */
void TermDesign::setScreenSize(int rows, int cols)
{
    printf("\E[8;%d;%d;t", rows, cols);
}