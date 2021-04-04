#include "../../include/MySimpleComputer.h"
int MySimpleComputer::DrawAccumulator()
{
    int error = 0;
    error += mt_gotoXY(2, 69);
    printf("+%04X", (unsigned int)accumulator.to_ulong());
    return error;
}
int MySimpleComputer::DrawOperation()
{
    int error = 0;
    int command, operand;
    error += mt_gotoXY(8, 68);
    if (sc_commandDecode(
                memory[instructionCounter].to_ulong(), command, operand)
        == -1) {
        std::cout << "+00 : 00";
    } else {
        printf("+%02X", command);
        printf(" : %02X", operand);
    }
    return error;
}