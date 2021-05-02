#include "../../include/ArithmeticLogicUnit.h"
/**
 * This function translates basic code into assembly analog.
 * @file TranslateBAS.cpp
 * @param filename - name of the file where basic code located
 * @return Operation result
 */
int ArithmeticLogicUnit::translateBAS(const std::string& filename)
{
    std::ifstream in;
    in.open(filename);
    if (in.is_open()) {
        if (in.good()) {
            int number;           // command number in basic
            int address;          // temp int for getting address
            char variable;        // temp char for getting variable
            std::ofstream out;    // output file
            std::string command;  // basic command
            std::string fileLine; // line in file
            std::vector<int> compare = juxtaposeCode(filename); // offsets
            if (compare.empty())
                return -1;
            out.open(filename.substr(0, filename.length() - 3) + "asm");
            for (int counter = 0, rems = 0; std::getline(in, fileLine);) {
                std::stringstream stringStream(fileLine); // get line by pieces
                stringStream >> number;  // get number of command
                stringStream >> command; // get command
                std::string result;
                if (command == "REM") {
                    ++rems;
                    continue;
                } else if (command == "END") {
                    result = commandEND(counter);
                } else if (command == "INPUT") {
                    result = commandINPUT(fileLine, counter);
                } else if (command == "OUTPUT") {
                    result = commandOUTPUT(fileLine, counter);
                } else if (command == "GOTO") {
                    result = commandGOTO(fileLine, counter, compare, rems);
                } else if (command == "IF") {
                    result = commandIF(fileLine, counter, compare, rems);
                } else if (command == "LET") {
                    result = commandLET(fileLine, counter);
                } else
                    return -1;
                if (!result.empty())
                    out << result;
                else
                    return -1;
            }
            out.close();
            return translateASM(
                    filename.substr(0, filename.length() - 3) + "asm");
        }
    }
    return -1;
}