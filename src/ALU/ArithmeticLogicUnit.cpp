#include "../../include/ArithmeticLogicUnit.h"
ArithmeticLogicUnit::ArithmeticLogicUnit()
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
}
void ArithmeticLogicUnit::ALU(int command, int operand)
{
    if (command == 0x10)
        commandRead(operand);
    else if (command == 0x11)
        commandWrite(operand);
    else if (command == 0x20)
        commandLoad(operand);
    else if (command == 0x21)
        commandStore(operand);
    else if (command == 0x30)
        commandAdd(operand);
    else if (command == 0x31)
        commandSub(operand);
    else if (command == 0x32)
        commandDivide(operand);
    else if (command == 0x33)
        commandMul(operand);
    else if (command == 0x40)
        commandJump(operand);
    else if (command == 0x41)
        commandJNEG(operand);
    else if (command == 0x42)
        commandJZ(operand);
    else if (command == 0x43)
        commandHalt(0);
    else if (command == 0x57)
        commandJNC(operand);
}
