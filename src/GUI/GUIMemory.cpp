#include "../../include/MySimpleComputer.h"
int MySimpleComputer::DrawMemory()
{
    int value, error = 0, command = 0, operand = 0;
    for (int row = 0; row < 10; ++row) {
        error += mt_gotoXY(2 + row, 2);
        for (int col = 0; col < 10; ++col) {
            if (row == instructionCounter / 10
                && col == instructionCounter % 10) {
                mt_setbgcolor(Cyan); // selected = colourful
            }
            sc_memoryGet(row * 10 + col, value);
            if ((value >> 14 & 1)) { // not a command
                printf(" %04X", value);
            } else { // is a command
                if (sc_commandDecode(value, command, operand) != -1) {
                    printf("+%02X", command);
                    printf("%02X", operand);
                } else { // command not found
                    printf(" %04X", value);
                }
            }
            printf(((col < 9) ? " " : ""));
            command = 0;
            operand = 0;
            mt_setbgcolor(Reset);
        }
    }
    if (error < 0) {
        return -1;
    }
    return 0;
}