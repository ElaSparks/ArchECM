#include "../../include/ArithmeticLogicUnit.h"
/**
 * This function translates basic code into assembly analog.
 * @file TranslateBAS.cpp
 * @param filename - name of the file where basic code located
 * @return Result of operation
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
            for (int counter = 0; std::getline(in, fileLine);) {
                std::istringstream stringStream(fileLine); // get line by pieces
                stringStream >> number;  // get number of command
                stringStream >> command; // get command
                out << std::setw(2) << std::setfill('0') << counter++;
                if (command == "REM") { // is REM command?
                    out << " JUMP " << compare[number / 10 - 1] + 1 << "\n";
                } else if (command == "END") { // is END command?
                    out << " HALT 00\n";
                } else if (command == "INPUT") { // is INPUT command?
                    stringStream >> variable;    // get variable
                    if (letterMemory(variable) == -1)
                        return -1;
                    else
                        out << " READ " << letterMemory(variable) << "\n";
                } else if (command == "OUTPUT") { // is OUTPUT command?
                    stringStream >> variable;     // get variable
                    if (letterMemory(variable) == -1) {
                        return -1;
                    } else {
                        out << " WRITE " << letterMemory(variable) << "\n";
                    }
                } else if (command == "GOTO") { // is OUTPUT command?
                    stringStream >> address;    // get address
                    out << " JUMP " << compare[address / 10 - 1] << "\n";
                } else if (command == "IF") { // is OUTPUT command?
                    stringStream >> variable; // get variable
                    if (letterMemory(variable) == -1)
                        return -1;
                    else {
                        out << " LOAD " << letterMemory(variable) << "\n";
                        out << std::setw(2) << std::setfill('0') << counter++;
                        if (fileLine.find("< 0 GOTO ") != -1) {
                            out << " JNEG ";
                        } else if (fileLine.find("== 0 GOTO ") != -1) {
                            out << " JZ ";
                        } else {
                            return -1;
                        }
                        stringStream.str(
                                fileLine.substr(fileLine.rfind("GOTO ") + 5));
                        stringStream >> address;
                        out << compare[address / 10 - 1] << "\n";
                    }
                } else if (command == "LET") { // is OUTPUT command?
                    char decVariable; // variable which is assigned a value
                    stringStream >> decVariable; // get variable
                    if (letterMemory(decVariable) == -1)
                        return -1;
                    else {
                        stringStream >> variable >> variable;
                        if (letterMemory(variable) == -1)
                            return -1;
                        else
                            out << " LOAD " << letterMemory(variable) << "\n";
                        if (fileLine.find(" + ") != -1
                            || fileLine.find(" - ") != -1
                            || fileLine.find(" * ") != -1
                            || fileLine.find(" / ") != -1) {
                            stringStream >> variable >> variable;
                            out << std::setw(2) << std::setfill('0')
                                << counter++;
                            if (fileLine.find(" + ") != -1) {
                                out << " ADD ";
                            } else if (fileLine.find(" - ") != -1) {
                                out << " SUB ";
                            } else if (fileLine.find(" * ") != -1) {
                                out << " MUL ";
                            } else if (fileLine.find(" / ") != -1) {
                                out << " DIVIDE ";
                            }
                            out << letterMemory(variable) << "\n";
                        }
                    }
                    out << std::setw(2) << std::setfill('0') << counter++;
                    out << " STORE " << letterMemory(decVariable) << "\n";
                }
            }
            out.close();
            return translateASM(
                    filename.substr(0, filename.length() - 3) + "asm");
        }
    }
    return -1;
}