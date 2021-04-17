#include "../../../include/ArithmeticLogicUnit.h"
void ArithmeticLogicUnit::commandAdd(int operand)
{
    int memoryValue, request;
    request = sc_memoryGet(operand, memoryValue);
    if (request < 0) {
        sc_regSet(std::abs(request), 1);
        return;
    }
    sc_accumulatorSet((accumulator + memoryValue));
}
void ArithmeticLogicUnit::commandSub(int operand)
{
    int memoryValue, request;
    request = sc_memoryGet(operand, memoryValue);
    if (request < 0) {
        sc_regSet(std::abs(request), 1);
        return;
    }
    sc_accumulatorSet((accumulator - memoryValue));
}
void ArithmeticLogicUnit::commandDivide(int operand)
{
    int memoryValue, request;
    request = sc_memoryGet(operand, memoryValue);
    if (request < 0) {
        sc_regSet(std::abs(request), 1);
        return;
    }
    if (memoryValue == 0) {
        sc_regSet(DIVISION_BY_ZERO, 1);
    } else
        sc_accumulatorSet((accumulator / memoryValue));
}
void ArithmeticLogicUnit::commandMul(int operand)
{
    int memoryValue, request;
    request = sc_memoryGet(operand, memoryValue);
    if (request < 0) {
        sc_regSet(std::abs(request), 1);
        return;
    }
    sc_accumulatorSet((accumulator * memoryValue));
}
