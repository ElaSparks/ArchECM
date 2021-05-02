#include "../../../include/ArithmeticLogicUnit.h"
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