#include "../../../include/ArithmeticLogicUnit.h"
void ArithmeticLogicUnit::commandLoad(int operand)
{
    int value, request;
    request = sc_memoryGet(operand, value);
    if (request < 0) {
        sc_regSet(std::abs(request), 1);
        return;
    }
    sc_accumulatorSet(value);
}
void ArithmeticLogicUnit::commandStore(int operand)
{
    int value, request;
    value = accumulator;
    request = sc_memorySet(operand, value);
    if (request < 0) {
        sc_regSet(std::abs(request), 1);
    }
}