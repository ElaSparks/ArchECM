#include "../../include/MySimpleComputer.h"
/**
 * The function draws on the screen the number of the current operation that is
 * being performed
 * @file GUIOperation.cpp
 * @return Operation result
 */
int MySimpleComputer::DrawOperation()
{
    int error = 0;
    int command, operand;
    error += move(8, 68);
    if (decodeCommand(memory[selector], command, operand) < 0) {
        std::cout << "+00 : 00";
    } else {
        printf("+%02X", command);
        printf(" : %02X", operand);
    }
    return error;
}