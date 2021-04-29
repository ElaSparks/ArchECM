#include "../../../include/ArithmeticLogicUnit.h"
/**
 * The function is equivalent to "mov EAX, value"
 * @file ALUMovEax.cpp
 * @param operand - the value to be set to the accumulator
 */
void ArithmeticLogicUnit::commandMOVEAX(int operand)
{
    if (operand >> 6) {
        if (operand != 0x40) {
            operand ^= 1 << 6;
        }
        operand = -operand;
    }
    accumulatorSet(operand);
}