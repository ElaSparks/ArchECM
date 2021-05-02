#include "../../../include/ArithmeticLogicUnit.h"
/**
 * The function is responsible for calculating all command offsets
 * @file JuxtaposeCode.cpp
 * @param filename - path to file
 * @return A vector in which the element number is equal to the line in BASIC
 * ((index +1) * 10), and the cell contains the corresponding number from which
 * this line begins in the assembler
 */
std::vector<int> ArithmeticLogicUnit::juxtaposeCode(const std::string& filename)
{
    std::ifstream in;
    in.open(filename);
    if (in.is_open()) {
        std::string command;     // stores the command we received from the file
        std::string fileLine;    // line in file
        std::vector<int> result; // vector of offsets
        for (int count = 0, rems = 0, number; std::getline(in, fileLine);) {
            std::istringstream stringStream(fileLine); // get line by pieces
            stringStream >> number;                    // get number of command
            stringStream >> command;                   // get command
            if (number < 10 || number > 900 || (number % 10 != 0))
                return std::vector<int>(); // such command number cannot exist
            if (number / 10 != result.size() + 1 + rems)
                return std::vector<int>(); // numbers are not in order
            if (command == "REM") {
                ++rems;
                continue;
            } else if (
                    command == "END" || command == "INPUT"
                    || command == "OUTPUT" || command == "GOTO") {
                result.push_back(count++);
            } else if (command == "IF") {
                result.push_back(count);
                count += 2;
            } else if (command == "LET") {
                result.push_back(count);
                if (fileLine.find(" + ") == -1 && fileLine.find(" - ") == -1
                    && fileLine.find(" * ") == -1
                    && fileLine.find(" / ") == -1) {
                    count += 2;
                } else {
                    count += 3;
                }
            } else { // something else
                return std::vector<int>();
            }
        }
        return result;
    }
    return std::vector<int>();
}