#include "../../include/MySimpleComputer.h"
/**
 * The function draws the contents of the accumulator to the GUI
 * @file GUIAccumulator.cpp
 * @return Operation result
 */
int MySimpleComputer::DrawAccumulator()
{
    int error = 0;
    error += move(2, 69);
    if (accumulator < 0) {
        printf("-");
    } else
        printf("+");
    printf("%04X", abs(accumulator));
    return error;
}
