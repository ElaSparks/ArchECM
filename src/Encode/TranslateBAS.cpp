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
            int number;               // command number in basic
            std::ofstream out;        // output file
            std::string command;      // basic command
            std::string fileLine;     // line in file
            std::vector<int> compare; // compare bas -> asm
            std::string result;
            out.open(filename.substr(0, filename.length() - 3) + "asm");
            for (int counter = 0; std::getline(in, fileLine);) {
                std::stringstream stringStream(fileLine); // get line by pieces
                std::string resultLine;
                stringStream >> number;  // get number of command
                stringStream >> command; // get command
                if (number < 10 || number > 900 || (number % 10 != 0))
                    return -1;
                if (number / 10 != compare.size() + 1)
                    return -1;
                compare.push_back(counter);
                if (command == "REM") {
                    continue;
                } else if (command == "END") {
                    resultLine = commandEND(counter);
                } else if (command == "INPUT") {
                    resultLine = commandINPUT(fileLine, counter);
                } else if (command == "OUTPUT") {
                    resultLine = commandOUTPUT(fileLine, counter);
                } else if (command == "GOTO") {
                    resultLine = commandGOTO(fileLine, counter);
                } else if (command == "IF") {
                    resultLine = commandIF(fileLine, counter);
                } else if (command == "LET") {
                    resultLine = commandLET(fileLine, counter);
                } else
                    return -1;
                if (!resultLine.empty())
                    result.append(resultLine);
                else
                    return -1;
            }
            if (compareGOTO(result, compare) == -1)
                return -1;
            out << result;
            out.close();
            return translateASM(
                    filename.substr(0, filename.length() - 3) + "asm");
        }
    }
    return -1;
}