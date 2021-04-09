#include "../../include/MySimpleComputer.h"
int MySimpleComputer::sc_regSet(int reg, int value)
{
    if ((reg >= 1) && (reg <= 5) && (value == 1 || value == 0)) {
        flags[reg - 1] = value;
        return 0;
    }
    return -1;
}
int MySimpleComputer::sc_regGet(int reg, int& value)
{
    if ((reg >= 1) && (reg <= 5)) {
        value = flags[reg - 1];
        return 0;
    }
    return -1;
}
int MySimpleComputer::sc_accumulatorSet(short value)
{
    if (value <= 0x3FFF && value >= -0x4000) {
        accumulator = value;
        sc_regSet(OVERFLOW, 0);
        return 0;
    }
    sc_regSet(OVERFLOW, 1);
    return -1;
}