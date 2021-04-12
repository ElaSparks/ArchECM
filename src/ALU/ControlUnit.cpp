#include "../../include/ArithmeticLogicUnit.h"
void ArithmeticLogicUnit::controlUnit()
{
    int memValue, command, operand;
    if (sc_memoryGet(instructionCounter, memValue) == -1) {
        return;
    }
    if (decodeCommand(memValue, command, operand) == -1) {
        return;
    }
    ALU(command, operand);
}