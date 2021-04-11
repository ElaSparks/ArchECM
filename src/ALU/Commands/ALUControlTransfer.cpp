#include "../../../include/ArithmeticLogicUnit.h"
int ArithmeticLogicUnit::commandJump(int operand)
{
    sc_instructionCounterSet(operand);
    return 0;
}
int ArithmeticLogicUnit::commandJNEG(int operand)
{
    if (accumulator < 0) {
        sc_instructionCounterSet(operand);
    }
    return 0;
}
int ArithmeticLogicUnit::commandJZ(int operand)
{
    if (accumulator == 0) {
        sc_instructionCounterSet(operand);
    }
    return 0;
}
int ArithmeticLogicUnit::commandJNC(int operand)
{
    if (flagsLO[OVERFLOW - 1] == 0) {
        sc_instructionCounterSet(operand);
    }
    return 0;
}
int ArithmeticLogicUnit::commandHalt()
{
    sc_regSet(IGNORE_IMPULSE, 1);
    sc_instructionCounterSet(0);
    return 0;
}
