#include "../../../include/ArithmeticLogicUnit.h"
void ArithmeticLogicUnit::commandJump(int operand)
{
    sc_instructionCounterSet(operand);
}
void ArithmeticLogicUnit::commandJNEG(int operand)
{
    if (accumulator < 0) {
        sc_instructionCounterSet(operand);
    }
}
void ArithmeticLogicUnit::commandJZ(int operand)
{
    if (accumulator == 0) {
        sc_instructionCounterSet(operand);
    }
}
void ArithmeticLogicUnit::commandJNC(int operand)
{
    if (flagsLO[OVERFLOW - 1] == 0) {
        sc_instructionCounterSet(operand);
    }
}
void ArithmeticLogicUnit::commandHalt()
{
    sc_regSet(IGNORE_IMPULSE, 1);
    sc_instructionCounterSet(0);
}
