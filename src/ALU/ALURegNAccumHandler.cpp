#include "../../include/ArithmeticLogicUnit.h"
int ArithmeticLogicUnit::sc_regSet(int reg, int value)
{
    if ((reg >= 1) && (reg <= 5) && (value == 1 || value == 0)) {
        flags[reg - 1] = value;
        return 0;
    }
    return -1;
}
int ArithmeticLogicUnit::sc_regGet(int reg, int& value)
{
    if ((reg >= 1) && (reg <= 5)) {
        value = flags[reg - 1];
        return 0;
    }
    return -1;
}
int ArithmeticLogicUnit::sc_accumulatorSet(int value)
{
    if (value <= 0x3FFF && value >= -0x4000) {
        accumulator = value;
        return 0;
    }
    sc_regSet(OVERFLOW, 1);
    return -1;
}
int ArithmeticLogicUnit::sc_instructionCounterSet(int address)
{
    if ((address >= 0) && (address <= 99)) {
        instructionCounter = address;
        return 0;
    }
    sc_regSet(OUT_OF_MEMORY, 1);
    return -1;
}