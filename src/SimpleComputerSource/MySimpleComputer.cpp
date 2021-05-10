#include "../../include/MySimpleComputer.h"
MySimpleComputer::MySimpleComputer()
{
    memoryInit();
    registerInit();
    accumulatorInit();
}
void MySimpleComputer::registerInit()
{
    flags.reset();
}
void MySimpleComputer::memoryInit()
{
    for (auto& item : memory) {
        item = 0;
    }
}
void MySimpleComputer::accumulatorInit()
{
    accumulator = 0;
}