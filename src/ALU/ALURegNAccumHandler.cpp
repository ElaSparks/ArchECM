#include "../../include/ArithmeticLogicUnit.h"
/**
 * The function sets the value for a specific register
 * @file ALURegNAccumHandler.cpp
 * @param reg - name or register number
 * @param value - value for register (enable or disable)
 * @return Operation result
 */
int ArithmeticLogicUnit::registerSet(int reg, int value)
{
    if ((reg >= 1) && (reg <= 5) && (value == 1 || value == 0)) {
        flags[reg - 1] = value;
        return 0;
    }
    return -1;
}
/**
 * The function returns the contents of a specific register by reference (into a
 * variable)
 * @file ALURegNAccumHandler.cpp
 * @param reg - name or register number
 * @param value - variable into which the register value will be placed
 * @return Operation result
 */
int ArithmeticLogicUnit::registerGet(int reg, int& value)
{
    if ((reg >= 1) && (reg <= 5)) {
        value = flags[reg - 1];
        return 0;
    }
    return -1;
}
/**
 * The function sets the value to the accumulator
 * @file ALURegNAccumHandler.cpp
 * @param value - the value to be set to the battery
 * @return Operation result
 */
int ArithmeticLogicUnit::accumulatorSet(int value)
{
    if (value <= 0x3FFF && value >= -0x4000) {
        accumulator = value;
        return 0;
    }
    registerSet(OVERFLOW, 1);
    return -1;
}
/**
 * The function allows you to go to a specific command by its number
 * @file ALURegNAccumHandler.cpp
 * @param address - memory cell number in which the command is located
 * @return Operation result
 */
int ArithmeticLogicUnit::instructionCounterSet(int address)
{
    if ((address >= 0) && (address <= 99)) {
        instructionCounter = address;
        return 0;
    }
    registerSet(OUT_OF_MEMORY, 1);
    return -1;
}