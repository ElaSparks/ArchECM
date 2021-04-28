#include "../../include/MySimpleComputer.h"
/**
 * The function draws on the screen the decoded cell value in the format of the
 * command number and the operand
 * @file GUIInstruction.cpp
 * @return Operation result
 */
int MySimpleComputer::DrawInstruction()
{
    int error = 0;
    error += move(5, 70);
    printf("%04X", instructionCounter);
    return error;
}