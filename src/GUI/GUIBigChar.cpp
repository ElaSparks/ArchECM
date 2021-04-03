#include "../../include/MySimpleComputer.h"
#include <sstream>
int MySimpleComputer::DrawBigChar()
{
    int value, error = 0, check = 0;
    if (sc_memoryGet(instructionCounter, value) != -1) {
        std::stringstream stream;
        if (value >> 14 & 1) { // not a command
            stream << std::setw(4) << std::setfill('0') << std::hex << value;
        } else {
            int command = 0, operand = 0;
            if (sc_commandDecode(value, command, operand) != -1) {
                stream << std::setw(2) << std::setfill('0') << std::hex
                       << command;
                stream << std::setw(2) << std::setfill('0') << std::hex
                       << operand;
                check = 1;
            } else {
                stream << std::setw(4) << std::setfill('0') << std::hex
                       << value;
            }
        }
        std::string result(stream.str());
        bc_printbigchar(bc_initbigchar(check ? '+' : ' '), 14, 2, Cyan, Black);
        bc_printbigchar(bc_initbigchar(result[0]), 14, 11, Cyan, Black);
        bc_printbigchar(bc_initbigchar(result[1]), 14, 20, Cyan, Black);
        bc_printbigchar(bc_initbigchar(result[2]), 14, 29, Cyan, Black);
        bc_printbigchar(bc_initbigchar(result[3]), 14, 38, Cyan, Black);
        if (error < 0) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}