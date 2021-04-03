#include "../../include/MySimpleComputer.h"
int MySimpleComputer::DrawFlags()
{
    int error = 0;
    int value = 0;
    std::string flagNames = "OZMIW";
    for (int i = 0; i < flagNames.length(); ++i) {
        error += mt_gotoXY(11, 68 + 2 * i);
        sc_regGet(i + 1, value);
        if (value) {
            mt_setbgcolor(Red);
        } else {
            mt_setbgcolor(Reset);
        }
        printf("%c", flagNames[i]);
    }
    mt_setbgcolor(Reset);
    if (error < 0) {
        return -1;
    }
    return 0;
}
int MySimpleComputer::DrawInstruction()
{
    int error = 0;
    error += mt_gotoXY(5, 70);
    printf("%04X", instructionCounter);
    return error;
}