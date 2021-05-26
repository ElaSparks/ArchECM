#include "../../../include/ArithmeticLogicUnit.h"
/**
 * Get address of letter in memory.
 * @file LetterEncode.cpp
 * @param symbol - name of variable
 * @return Error or position of variable in memory
 */
int ArithmeticLogicUnit::letterAddress(char symbol)
{
    if (symbol >= 'A' && symbol <= 'Z') {
        return dataAddress - (symbol - 'A');
    }
    return -1;
}