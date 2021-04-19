#include "../../include/ArithmeticLogicUnit.h"

int ArithmeticLogicUnit::translateBAS(const std::string& filename)
{
    std::ifstream in;
    if (in.is_open()) {
        if (in.good()) {
            std::string strLine;           // line in file
            std::ofstream out;             // output file
            int commandNumber = 0;         // number of current command
            std::vector<int> compare(100); // compare start bas && asm command
            out.open(filename.substr(0, filename.length() - 3) + "asm");
            while (std::getline(in, strLine)) {        // while eof
                std::istringstream strStream(strLine); // get piece of line
                int number;                            // command number in bas
                std::string command;                   // bas command
                strStream >> number;                   // get number of command
                if (number < 10 || number > 1000 || (number % 10 != 0)) {
                    in.close(); // syntax error
                    out.close();
                    return -1;
                }
                strStream >> command; // get command
                out << std::setw(2) << std::setfill('0') << commandNumber
                    << " ";
                if (command == "REM") { // is REM command?
                    compare[number / 10 - 1] = commandNumber;
                    out << "JUMP " << compare[number / 10 - 1] + 1 << "\n";
                    ++commandNumber;
                } else if (command == "END") { // is END command?
                    compare[number / 10 - 1] = commandNumber;
                    out << "HALT 00"
                        << "\n";
                    ++commandNumber;
                } else if (command == "INPUT") { // is INPUT command?
                    char variable;
                    strStream >> variable; // get variable
                    int resultRequest = letterMemory(variable);
                    if (resultRequest == -1) {
                        in.close(); // syntax error
                        out.close();
                        return -1;
                    } else {
                        out << "READ " << resultRequest << "\n";
                        ++commandNumber;
                    }
                } else if (command == "OUTPUT") { // is OUTPUT command?
                    char variable;
                    strStream >> variable; // get variable
                    int resultRequest = letterMemory(variable);
                    if (resultRequest == -1) {
                        in.close(); // syntax error
                        out.close();
                        return -1;
                    } else {
                        out << "WRITE " << resultRequest << "\n";
                        ++commandNumber;
                    }
                }
            }
            return 0;
        }
    }
    return -1;
}