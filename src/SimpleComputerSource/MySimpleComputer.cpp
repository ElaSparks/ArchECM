#include "../../include/MySimpleComputer.h"
MySimpleComputer::MySimpleComputer()
{
    sc_memoryInit();
    sc_regInit();
    sc_accumulatorInit();
}
void MySimpleComputer::sc_regInit()
{
    flags.reset();
}
void MySimpleComputer::sc_memoryInit()
{
    for (auto& item : memory) {
        item = 0;
    }
}
void MySimpleComputer::sc_accumulatorInit()
{
    accumulator = 0;
}