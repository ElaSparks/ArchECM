#include "../../include/ArithmeticLogicUnit.h"
/**
 * The function ensures the operation of the control device
 * @file ControlUnit.cpp
 */
void ArithmeticLogicUnit::controlUnit()
{
    int memValue, command, operand, request;
    request = memoryGet(instructionCounter, memValue);
    if (request < 0) {
        registerSet(std::abs(request), 1);
        return;
    }
    request = decodeCommand(memValue, command, operand);
    if (request < 0) {
        registerSet(std::abs(request), 1);
        return;
    }
    ALU(command, operand);
}