#include "../../include/ArithmeticLogicUnit.h"
int ArithmeticLogicUnit::sc_memorySet(int address, int value)
{
    if ((address >= 0) && (address <= 99)) {
        if (value <= 0x3FFF && value >= -0x4000) {
            memory[address] = value;
            return 0;
        }
        sc_regSet(OVERFLOW, 1);
        return -1;
    }
    sc_regSet(OUT_OF_MEMORY, 1);
    return -1;
}
int ArithmeticLogicUnit::sc_memoryGet(int address, int& value)
{
    if ((address >= 0) && (address <= 99)) {
        value = memory[address];
        return 0;
    }
    sc_regSet(OUT_OF_MEMORY, 1);
    return -1;
}