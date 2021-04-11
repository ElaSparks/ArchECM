#include "../../../include/ArithmeticLogicUnit.h"
int ArithmeticLogicUnit::commandAdd(int operand)
{
    short memoryValue;
    sc_memoryGet(operand, memoryValue);
    sc_accumulatorSet((accumulator + memoryValue));
    return 0;
}
int ArithmeticLogicUnit::commandSub(int operand)
{
    short memoryValue;
    sc_memoryGet(operand, memoryValue);
    sc_accumulatorSet((accumulator - memoryValue));
    return 0;
}
int ArithmeticLogicUnit::commandDivide(int operand)
{
    short memoryValue;
    sc_memoryGet(operand, memoryValue);
    if (memoryValue == 0) {
        sc_regSet(DIVISION_BY_ZERO, 1);
    } else
        sc_accumulatorSet((accumulator / memoryValue));
    return 0;
}
int ArithmeticLogicUnit::commandMul(int operand)
{
    short memoryValue;
    sc_memoryGet(operand, memoryValue);
    sc_accumulatorSet((accumulator * memoryValue));
    return 0;
}
