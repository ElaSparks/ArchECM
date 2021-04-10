#include "../../include/MySimpleComputer.h"
int MySimpleComputer::DrawAccumulator()
{
    int error = 0;
    error += mt_gotoXY(2, 69);
    if (accumulator < 0) {
        printf("-");
    } else
        printf("+");
    printf("%04X", abs(accumulator));
    return error;
}
int MySimpleComputer::DrawOperation()
{
    int error = 0;
    int command, operand;
    error += mt_gotoXY(8, 68);
    if (decodeCommand(memory[instructionCounter], command, operand) == -1) {
        std::cout << "+00 : 00";
    } else {
        printf("+%02X", command);
        printf(" : %02X", operand);
    }
    return error;
}