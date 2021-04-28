#include "../../include/MySimpleComputer.h"
int MySimpleComputer::DrawMemory()
{
    int value, command = 0, operand = 0;
    int error = 0;
    for (int row = 0; row < 10; ++row) {
        error += move(2 + row, 2);
        for (int col = 0; col < 10; ++col) {
            if (row == instructionCounter / 10
                && col == instructionCounter % 10) {
                setBackgroundColor(Yellow); // selected = colourful
            }
            if (row == selector / 10 && col == selector % 10) {
                setBackgroundColor(Cyan); // selected = colourful
            }
            memoryGet(row * 10 + col, value);
            if ((value >> 14 & 1)) { // not a command
                if (value < 0) {
                    printf("-");
                } else
                    printf(" ");
            } else { // is a command
                if (decodeCommand(value, command, operand) == 0) {
                    printf("+");
                } else { // command not found
                    if (value < 0) {
                        printf("-");
                    } else
                        printf(" ");
                }
            }
            printf("%04X", std::abs(value));
            printf(((col < 9) ? " " : ""));
            command = 0;
            operand = 0;
            setBackgroundColor(Reset);
        }
    }
    if (error < 0) {
        return -1;
    }
    return 0;
}