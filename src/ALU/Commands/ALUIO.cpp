#include "../../../include/ArithmeticLogicUnit.h"
void ArithmeticLogicUnit::commandRead(int operand)
{
    newTimer.it_interval.tv_sec = 0;
    newTimer.it_interval.tv_usec = 0;
    newTimer.it_value.tv_sec = 0;
    newTimer.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &newTimer, &oldTimer);
    int value = 0, request;
    rk_switchecho();
    std::cout << "Input: ";
    std::cin >> value;
    rk_switchecho();
    request = sc_memorySet(operand, value);
    setitimer(ITIMER_REAL, &oldTimer, &newTimer);
    if (request < 0) {
        sc_regSet(std::abs(request), 1);
    }
}
void ArithmeticLogicUnit::commandWrite(int operand)
{
    newTimer.it_interval.tv_sec = 0;
    newTimer.it_interval.tv_usec = 0;
    newTimer.it_value.tv_sec = 0;
    newTimer.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &newTimer, &oldTimer);
    int value = 0, request;
    request = sc_memoryGet(operand, value);
    std::cout << "Output: " << value << std::endl;
    std::cout << "Press enter key to continue..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getchar();
    setitimer(ITIMER_REAL, &oldTimer, &newTimer);
    if (request < 0) {
        sc_regSet(std::abs(request), 1);
    }
}
