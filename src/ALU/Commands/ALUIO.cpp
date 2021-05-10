#include "../../../include/ArithmeticLogicUnit.h"
/**
 * Broadcasting the READ Command. The number entered by the user is placed in
 * the memory location specified by the operand
 * @file ALUIO.cpp
 * @param operand - in which cell the value read from the keyboard will be
 * placed
 */
void ArithmeticLogicUnit::commandRead(int operand)
{
    newTimer.it_interval.tv_sec = 0;
    newTimer.it_interval.tv_usec = 0;
    newTimer.it_value.tv_sec = 0;
    newTimer.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &newTimer, &oldTimer);
    int value = 0, request;
    switchEcho();
    std::cout << "Input: ";
    std::cin >> value;
    switchEcho();
    request = memorySet(operand, value);
    setitimer(ITIMER_REAL, &oldTimer, &newTimer);
    if (request < 0) {
        registerSet(std::abs(request), 1);
    }
}
/**
 * Broadcasting the WRITE Command. The value of the memory cell whose address is
 * specified in the operand will be displayed.
 * @file ALUIO.cpp
 * @param operand - cell number whose value will be displayed
 * be written
 */
void ArithmeticLogicUnit::commandWrite(int operand)
{
    newTimer.it_interval.tv_sec = 0;
    newTimer.it_interval.tv_usec = 0;
    newTimer.it_value.tv_sec = 0;
    newTimer.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &newTimer, &oldTimer);
    int value = 0, request;
    request = memoryGet(operand, value);
    std::cout << "Output: " << value << std::endl;
    std::cout << "Press enter key to continue..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getchar();
    setitimer(ITIMER_REAL, &oldTimer, &newTimer);
    if (request < 0) {
        registerSet(std::abs(request), 1);
    }
}
