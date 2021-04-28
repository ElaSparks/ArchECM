#include "../../../include/ArithmeticLogicUnit.h"
/**
 * Broadcasting the ADD Command. Adds a word in an accumulator and a word from
a specified memory location (result in accumulator)
 * @file ALUArithmetic.cpp
 * @param operand - memory address
 */
void ArithmeticLogicUnit::commandAdd(int operand)
{
    int memoryValue, request;
    request = memoryGet(operand, memoryValue);
    if (request < 0) {
        registerSet(std::abs(request), 1);
        return;
    }
    accumulatorSet((accumulator + memoryValue));
}
/**
 * Broadcasting the SUB Command. Subtracts from the word in the accumulator the
word from the specified memory location (result in accumulator)
 * @file ALUArithmetic.cpp
 * @param operand - memory address
 */
void ArithmeticLogicUnit::commandSub(int operand)
{
    int memoryValue, request;
    request = memoryGet(operand, memoryValue);
    if (request < 0) {
        registerSet(std::abs(request), 1);
        return;
    }
    accumulatorSet((accumulator - memoryValue));
}
/**
 * Broadcasting the DIVIDE Command. Divides a word in an accumulator by a word
from a specified memory location (result in accumulator)
 * @file ALUArithmetic.cpp
 * @param operand - memory address
 */
void ArithmeticLogicUnit::commandDivide(int operand)
{
    int memoryValue, request;
    request = memoryGet(operand, memoryValue);
    if (request < 0) {
        registerSet(std::abs(request), 1);
        return;
    }
    if (memoryValue == 0) {
        registerSet(DIVISION_BY_ZERO, 1);
    } else
        accumulatorSet((accumulator / memoryValue));
}
/**
 * Broadcasting the MUL Command. Multiplies a word in an accumulator by a word
from a specified memory location (result in accumulator)
 * @file ALUArithmetic.cpp
 * @param operand - memory address
 */
void ArithmeticLogicUnit::commandMul(int operand)
{
    int memoryValue, request;
    request = memoryGet(operand, memoryValue);
    if (request < 0) {
        registerSet(std::abs(request), 1);
        return;
    }
    accumulatorSet((accumulator * memoryValue));
}
