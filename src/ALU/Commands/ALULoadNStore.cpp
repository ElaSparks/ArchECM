#include "../../../include/ArithmeticLogicUnit.h"
void ArithmeticLogicUnit::commandLoad(int operand)
{
    int value;
    sc_memoryGet(operand, value);
    sc_accumulatorSet(value);
}
void ArithmeticLogicUnit::commandStore(int operand)
{
    int value;
    value = accumulator;
    sc_memorySet(operand, value);
}