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
            std::string strLine;          // line in file
            std::ofstream out;            // output file
            int commandNumber = 0;        // number of current command
            std::vector<int> compare(90); // compare start bas && asm command
            out.open(filename.substr(0, filename.length() - 3) + "asm");
            // calculating all command offsets
            while (std::getline(in, strLine)) { // while eof
                std::istringstream strStream(strLine);
                std::string command;
                int number;
                strStream >> number;  // get number of command
                strStream >> command; // get command
                if (number < 10 || number > 900 || (number % 10 != 0)) {
                    out << "[error]\n";
                    in.close(); // syntax error
                    out.close();
                    return -1;
                }
                if (command == "REM" || command == "END" || command == "INPUT"
                    || command == "OUTPUT" || command == "GOTO") {
                    compare[number / 10 - 1] = commandNumber;
                    ++commandNumber;
                } else if (command == "IF") {
                    compare[number / 10 - 1] = commandNumber;
                    commandNumber += 2;
                } else if (command == "LET") {
                    compare[number / 10 - 1] = commandNumber;
                    if (strLine.find(" + ") == -1 && strLine.find(" - ") == -1
                        && strLine.find(" * ") == -1
                        && strLine.find(" / ") == -1) {
                        commandNumber += 2;
                    } else {
                        commandNumber += 3;
                    }
                } else {
                    out << "[error]\n";
                    in.close(); // syntax error
                    out.close();
                    return -1;
                }
            }
            commandNumber = 0;
            in.clear();
            in.seekg(0);
            while (std::getline(in, strLine)) {        // while eof
                std::istringstream strStream(strLine); // get piece of line
                int number;                            // command number in bas
                std::string command;                   // bas command
                strStream >> number;                   // get number of command
                strStream >> command;                  // get command
                out << std::setw(2) << std::setfill('0') << commandNumber
                    << " ";
                ++commandNumber;
                if (command == "REM") { // is REM command?
                    out << "JUMP " << compare[number / 10 - 1] + 1 << "\n";
                } else if (command == "END") { // is END command?
                    out << "HALT 00\n";
                } else if (command == "INPUT") { // is INPUT command?
                    char variable;
                    strStream >> variable; // get variable
                    int resultRequest = letterMemory(variable);
                    if (resultRequest == -1) {
                        out << "\n[error]\n";
                        in.close(); // syntax error
                        out.close();
                        return -1;
                    } else {
                        out << "READ " << resultRequest << "\n";
                    }
                } else if (command == "OUTPUT") { // is OUTPUT command?
                    char variable;
                    strStream >> variable; // get variable
                    int resultRequest = letterMemory(variable);
                    if (resultRequest == -1) {
                        out << "\n[error]\n";
                        in.close(); // syntax error
                        out.close();
                        return -1;
                    } else {
                        out << "WRITE " << resultRequest << "\n";
                    }
                } else if (command == "GOTO") { // is OUTPUT command?
                    int address;
                    strStream >> address; // get address
                    out << "JUMP " << compare[address / 10 - 1] << "\n";
                } else if (command == "IF") { // is OUTPUT command?
                    char variable;
                    strStream >> variable; // get variable
                    int resultRequest = letterMemory(variable);
                    if (resultRequest == -1) {
                        out << "\n[error]\n";
                        in.close(); // syntax error
                        out.close();
                        return -1;
                    } else {
                        out << "LOAD " << resultRequest << "\n";
                        out << std::setw(2) << std::setfill('0')
                            << commandNumber << " ";
                        ++commandNumber;
                        if (strLine.rfind("< 0 GOTO ") != -1) {
                            int address;
                            strStream.str(
                                    strLine.substr(strLine.rfind("< 0 GOTO ")));
                            strStream >> address;
                            out << "JNEG " << compare[address / 10 - 1] << "\n";
                        } else if (strLine.rfind("== 0 GOTO ") != -1) {
                            int address;
                            strStream.str(strLine.substr(
                                    strLine.rfind("== 0 GOTO ")));
                            strStream >> address;
                            out << "JZ " << compare[address / 10 - 1] << "\n";
                        } else {
                            out << "\n[error]\n";
                            in.close(); // syntax error
                            out.close();
                            return -1;
                        }
                    }
                } else if (command == "LET") { // is OUTPUT command?
                    char decVariable;
                    strStream >> decVariable; // get variable
                    int resultRequest = letterMemory(decVariable);
                    if (resultRequest == -1) {
                        out << "\n[error]\n";
                        in.close(); // syntax error
                        out.close();
                        return -1;
                    } else {
                        char variable;
                        strStream >> variable >> variable;
                        int result = letterMemory(variable);
                        out << "LOAD " << result << "\n";
                        if (strLine.find(" + ") != -1) {
                            strStream >> variable >> variable;
                            out << std::setw(2) << std::setfill('0')
                                << commandNumber << " ";
                            result = letterMemory(variable);
                            out << "ADD " << result << "\n";
                            ++commandNumber;
                        } else if (strLine.find(" - ") != -1) {
                            strStream >> variable >> variable;
                            out << std::setw(2) << std::setfill('0')
                                << commandNumber << " ";
                            result = letterMemory(variable);
                            out << "SUB " << result << "\n";
                            ++commandNumber;
                        } else if (strLine.find(" * ") != -1) {
                            strStream >> variable >> variable;
                            out << std::setw(2) << std::setfill('0')
                                << commandNumber << " ";
                            result = letterMemory(variable);
                            out << "MUL " << result << "\n";
                            ++commandNumber;
                        } else if (strLine.find(" / ") != -1) {
                            strStream >> variable >> variable;
                            out << std::setw(2) << std::setfill('0')
                                << commandNumber << " ";
                            result = letterMemory(variable);
                            out << "DEVIDE " << result << "\n";
                            ++commandNumber;
                        }
                    }
                    out << std::setw(2) << std::setfill('0') << commandNumber
                        << " ";
                    out << "STORE " << resultRequest << "\n";
                    ++commandNumber;
                }
            }
            return 0;
        }
    }
    return -1;
}