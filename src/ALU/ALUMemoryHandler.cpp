#include "../../include/ArithmeticLogicUnit.h"
/**
 * The function sets the value for a specific memory location
 * @file ALUMemoryHandler.cpp
 * @param address - the address of the cell where we set the value
 * @param value - the memory value we are setting
 * @return Operation result
 */
int ArithmeticLogicUnit::memorySet(int address, int value)
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
/**
 * The function gets the value of a specific memory location and places it in a
 * variable
 * @file ALUMemoryHandler.cpp
 * @param address - the address of the cell the contents of which you want to
 * get
 * @param value - a variable into which the value of a specific memory location
 * will be placed
 * @return Operation result
 */
int ArithmeticLogicUnit::memoryGet(int address, int& value)
{
    if ((address >= 0) && (address <= 99)) {
        value = memory[address];
        return 0;
    }
    return -OUT_OF_MEMORY;
}