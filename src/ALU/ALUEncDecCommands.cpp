#include "../../include/ArithmeticLogicUnit.h"
/**
 * The function encodes the command with the specified number and operand and
 * puts the result in value
 * @file ALUEncDecCommands.cpp
 * @param command - simple computer command
 * @param operand - the object on which a machine instruction is being executed
 * @param value - variable to which the result will be
 * @return Operation result
 */
int ArithmeticLogicUnit::encodeCommand(int command, int operand, int& value)
{
    if (std::find(commands.begin(), commands.end(), command)
        == commands.end()) {
        return -WRONG_COMMAND;
    }
    if (command == 0x77) {
        if (operand <= 0x3F && operand >= -0x40) {
            value = command << 7;
            if (operand < 0) {
                value |= std::abs(operand);
                value |= 1 << 6;
            } else {
                value |= operand;
            }

            return 0;
        }
        return -OVERFLOW;
    }
    if ((operand < 0) || (operand > 99)) {
        return -OUT_OF_MEMORY;
    }
    value = command << 7 | operand;
    return 0;
}
/**
 * The function decodes the value as a Simple Computer command
 * @file ALUEncDecCommands.cpp
 * @param command - variable in which the command will be placed
 * @param operand - variable in which the operand will be placed
 * @param value - the value to be decoded
 * @return Operation result
 */
int ArithmeticLogicUnit::decodeCommand(int value, int& command, int& operand)
{
    if ((std::find(commands.begin(), commands.end(), value >> 7)
         == commands.end())
        || (value >> 14 & 1)) {
        return -WRONG_COMMAND;
    }
    if (value >> 7 == 0x77) {
        command = value >> 7;
        operand = value & 127;
        return 0;
    }
    if (((value & 127) < 0) || ((value & 127) > 99)) {
        return -OUT_OF_MEMORY;
    }
    command = value >> 7;
    operand = value & 127;
    return 0;
}