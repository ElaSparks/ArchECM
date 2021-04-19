#include "../../include/ArithmeticLogicUnit.h"
int ArithmeticLogicUnit::encodeCommand(int command, int operand, int& value)
{
    if (std::find(commands.begin(), commands.end(), command)
        == commands.end()) {
        return -WRONG_COMMAND;
    }
    if ((operand < 0) || (operand > 99)) {
        return -OUT_OF_MEMORY;
    }
    value = command << 7 | operand;
    return 0;
}
int ArithmeticLogicUnit::decodeCommand(int value, int& command, int& operand)
{
    if ((std::find(commands.begin(), commands.end(), value >> 7)
         == commands.end())
        || (value >> 14 & 1)) {
        return -WRONG_COMMAND;
    }
    if (((value & 127) < 0) || ((value & 127) > 99)) {
        return -OUT_OF_MEMORY;
    }
    command = value >> 7;
    operand = value & 127;
    return 0;
}