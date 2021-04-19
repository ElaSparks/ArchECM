#include "../../include/ArithmeticLogicUnit.h"
void ArithmeticLogicUnit::controlUnit()
{
    int memValue, command, operand, request;
    request = sc_memoryGet(instructionCounter, memValue);
    if (request < 0) {
        sc_regSet(std::abs(request), 1);
        return;
    }
    request = decodeCommand(memValue, command, operand);
    if (request < 0) {
        sc_regSet(std::abs(request), 1);
        return;
    }
    ALU(command, operand);
}