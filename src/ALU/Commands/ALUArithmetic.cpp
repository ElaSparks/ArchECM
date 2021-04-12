#include "../../../include/ArithmeticLogicUnit.h"
void ArithmeticLogicUnit::commandAdd(int operand)
{
    int memoryValue;
    sc_memoryGet(operand, memoryValue);
    sc_accumulatorSet((accumulator + memoryValue));
}
void ArithmeticLogicUnit::commandSub(int operand)
{
    int memoryValue;
    sc_memoryGet(operand, memoryValue);
    sc_accumulatorSet((accumulator - memoryValue));
}
void ArithmeticLogicUnit::commandDivide(int operand)
{
    int memoryValue;
    sc_memoryGet(operand, memoryValue);
    if (memoryValue == 0) {
        sc_regSet(DIVISION_BY_ZERO, 1);
    } else
        sc_accumulatorSet((accumulator / memoryValue));
}
void ArithmeticLogicUnit::commandMul(int operand)
{
    int memoryValue;
    sc_memoryGet(operand, memoryValue);
    sc_accumulatorSet((accumulator * memoryValue));
}
