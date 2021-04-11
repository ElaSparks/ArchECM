#include "../../../include/ArithmeticLogicUnit.h"
int ArithmeticLogicUnit::commandLoad(int operand)
{
    short value;
    sc_memoryGet(operand, value);
    sc_accumulatorSet(value);
    return 0;
}
int ArithmeticLogicUnit::commandStore(int operand)
{
    short value;
    value = accumulator;
    sc_memorySet(operand, value);
    return 0;
}