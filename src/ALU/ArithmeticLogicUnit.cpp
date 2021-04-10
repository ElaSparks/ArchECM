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
int ArithmeticLogicUnit::ALU(int command, int operand)
{
    //    if (command == 0x10)
    //        return commandRead(operand);
    //    else if (command == 0x11)
    //        return commandWrite(operand);
    //    else if (command == 0x20)
    //        return commandLoad(operand);
    //    else if (command == 0x21)
    //        return commandStore(operand);
    //    else if (command == 0x30)
    //        return commandAdd(operand);
    //    else if (command == 0x31)
    //        return commandSub(operand);
    //    else if (command == 0x32)
    //        return commandDivide(operand);
    //    else if (command == 0x33)
    //        return commandMul(operand);
    //    else if (command == 0x40)
    //        return commandJump(operand);
    //    else if (command == 0x41)
    //        return commandJNEG(operand);
    //    else if (command == 0x42)
    //        return commandJZ(operand);
    //    else if (command == 0x43)
    //        return commandHalt();
    //    else if (command == 0x57)
    //        return commandJNC(operand);
    //    return -1;
}
