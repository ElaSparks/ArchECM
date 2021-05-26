#include "../../../include/ArithmeticLogicUnit.h"
/**
 * The function gets the type of the operation and returns its priority
 * @param operation - type of operation
 * @return Operation priority
 */
int ArithmeticLogicUnit::getPriority(int operation)
{
    switch (operation) {
    case '+':
    case '-':
        return 0;
    case '*':
    case '/':
        return 1;
    default:
        return -1;
    }
}