#include "../../../include/ArithmeticLogicUnit.h"
/**
 * Broadcasting the LOAD Command. Loading into an accumulator a value from a
 * specified memory address.
 * @file ALULoadNStore.cpp
 * @param operand - memory address
 */
void ArithmeticLogicUnit::commandLoad(int operand)
{
    int value, request;
    request = memoryGet(operand, value);
    if (request < 0) {
        registerSet(std::abs(request), 1);
        return;
    }
    accumulatorSet(value);
}
/**
 * Broadcasting the STORE Command. Unloads a value from the accumulator at the
 * specified memory address.
 * @file ALULoadNStore.cpp
 * @param operand - memory address
 */
void ArithmeticLogicUnit::commandStore(int operand)
{
    int value, request;
    value = accumulator;
    request = memorySet(operand, value);
    if (request < 0) {
        registerSet(std::abs(request), 1);
    }
}