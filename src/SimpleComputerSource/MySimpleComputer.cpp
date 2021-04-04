#include "../../include/MySimpleComputer.h"
MySimpleComputer::MySimpleComputer()
    : commands(
            {0x10,
             0x11,
             0x20,
             0x21,
             0x30,
             0x31,
             0x32,
             0x33,
             0x40,
             0x41,
             0x42,
             0x43,
             0x57})
{
    sc_memoryInit();
    sc_regInit();
}
void MySimpleComputer::sc_regInit()
{
    flags.reset();
}
void MySimpleComputer::sc_memoryInit()
{
    for (auto& item : memory) {
        item.reset();
    }
}
