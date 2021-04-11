#include "../../../include/ArithmeticLogicUnit.h"
int ArithmeticLogicUnit::commandRead(int operand)
{
    rk_switchecho();
    newTimer.it_interval.tv_sec = 0;
    newTimer.it_interval.tv_usec = 0;
    newTimer.it_value.tv_sec = 0;
    newTimer.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &newTimer, &oldTimer);
    short value = 0;
    std::cout << "Input: ";
    std::cin >> value;
    sc_memorySet(operand, value);
    rk_switchecho();
    setitimer(ITIMER_REAL, &oldTimer, &newTimer);
    return 0;
}
int ArithmeticLogicUnit::commandWrite(int operand)
{
    newTimer.it_interval.tv_sec = 0;
    newTimer.it_interval.tv_usec = 0;
    newTimer.it_value.tv_sec = 0;
    newTimer.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &newTimer, &oldTimer);
    short value = 0;
    sc_memoryGet(operand, value);
    std::cout << "Output: " << value << std::endl;
    setitimer(ITIMER_REAL, &oldTimer, &newTimer);
    return 0;
}
