#include "../include/MySimpleComputer.h"
int MySimpleComputer::sc_regSet(int reg, int value)
{
    if ((reg >= 1) && (reg <= 5) && (value == 1 || value == 0)) {
        flags[reg - 1] = value;
        return 0;
    }
    return -1;
}
int MySimpleComputer::sc_regGet(int reg, int& value)
{
    if ((reg >= 1) && (reg <= 5)) {
        value = flags[reg - 1];
        return 0;
    }
    return -1;
}
int MySimpleComputer::sc_commandEncode(int command, int operand, int& value)
{
    if (std::find(commands.begin(), commands.end(), command)
        == commands.end()) {
        sc_regSet(WRONG_COMMAND, 1);
        return -1;
    }
    if ((operand >= 0) && (operand <= 99)) {
        sc_regSet(OUT_OF_MEMORY, 1);
        return -1;
    }
    sc_regSet(OUT_OF_MEMORY, 0);
    sc_regSet(WRONG_COMMAND, 0);
    value = command << 7 | operand;
    return 0;
}
int MySimpleComputer::sc_commandDecode(int value, int& command, int& operand)
{
    if (((std::find(commands.begin(), commands.end(), value >> 7)
          != commands.end())
         && (!(value >> 14 & 1)))
        && (((value & 127) >= 0) && ((value & 127) <= 99))) {
        command = value >> 7;
        operand = value & 127;
        return 0;
    }
    return -1;
}