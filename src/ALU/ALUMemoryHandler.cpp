#include "../../include/ArithmeticLogicUnit.h"
int ArithmeticLogicUnit::sc_memorySet(int address, int value)
{
    if ((address >= 0) && (address <= 99)) {
        if (value <= 0x3FFF && value >= -0x4000) {
            memory[address] = value;
            return 0;
        }
        return -OVERFLOW;
    }
    return -OUT_OF_MEMORY;
}
int ArithmeticLogicUnit::sc_memoryGet(int address, int& value)
{
    if ((address >= 0) && (address <= 99)) {
        value = memory[address];
        return 0;
    }
    return -OUT_OF_MEMORY;
}