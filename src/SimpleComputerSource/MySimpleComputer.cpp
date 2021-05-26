#include "../../include/MySimpleComputer.h"
/**
 * Constructor of MySimpleComputer class. Flush all components.
 * @file MySimpleComputer.cpp
 */
MySimpleComputer::MySimpleComputer()
{
    memoryInit();
    registerInit();
    accumulatorInit();
}
/**
 * Flush the flag register.
 * @file MySimpleComputer.cpp
 */
void MySimpleComputer::registerInit()
{
    flags.reset();
}
/**
 * Flush the contents of memory.
 * @file MySimpleComputer.cpp
 */
void MySimpleComputer::memoryInit()
{
    for (auto& item : memory) {
        item = 0;
    }
}
/**
 * Flush the contents of accumulator.
 * @file MySimpleComputer.cpp
 */
void MySimpleComputer::accumulatorInit()
{
    accumulator = 0;
}