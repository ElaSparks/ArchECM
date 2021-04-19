#include "../../include/ArithmeticLogicUnit.h"
/**
 * @author ElaSparks
 * @param symbol - name of variable
 * @return error or position of variable in memory
 */
int ArithmeticLogicUnit::letterMemory(char symbol)
{
    if (symbol >= 'A' && symbol <= 'J') {
        return 90 + symbol - 'A';
    }
    return -1;
}