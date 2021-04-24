#include "../../include/ArithmeticLogicUnit.h"
/**
 * @author ElaSparks
 * @file LetterEncode.cpp
 * @param symbol - name of variable
 * @return Error or position of variable in memory
 */
int ArithmeticLogicUnit::letterMemory(char symbol)
{
    if (symbol >= 'A' && symbol <= 'J') {
        return 90 + symbol - 'A';
    }
    return -1;
}