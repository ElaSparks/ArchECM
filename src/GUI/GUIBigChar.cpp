#include "../../include/MySimpleComputer.h"
/**
 * The function takes the contents of the selected cell and displays it
 * character by character in the "BigChar" format
 * @file GUIBigChar.cpp
 * @return Operation result
 */
int MySimpleComputer::DrawBigChar()
{
    int value;
    int error = 0, check = 0;
    if (memoryGet(selector, value) != -1) {
        std::stringstream stream;
        if (value >> 14 & 1) { // not a command
            if (value < 0) {
                check = -1;
            }
        } else {
            int command = 0, operand = 0;
            if (decodeCommand(value, command, operand) == 0) {
                check = 1;
            } else {
                if (value < 0) {
                    check = -1;
                }
            }
        }
        stream << std::setw(4) << std::setfill('0') << std::hex
               << std::abs(value);
        std::string result(stream.str());
        printBigChar(
                initBigChar(check == 1 ? '+' : ((check == -1) ? '-' : ' ')),
                14,
                2,
                Cyan,
                Black);
        printBigChar(initBigChar(result[0]), 14, 11, Cyan, Black);
        printBigChar(initBigChar(result[1]), 14, 20, Cyan, Black);
        printBigChar(initBigChar(result[2]), 14, 29, Cyan, Black);
        printBigChar(initBigChar(result[3]), 14, 38, Cyan, Black);
        if (error < 0) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}