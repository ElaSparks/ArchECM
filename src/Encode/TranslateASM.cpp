#include "../../include/ArithmeticLogicUnit.h"
/**
 * This function translates assembly code into simple computer commands and
 * loads them into memory.
 * @file TranslateASM.cpp
 * @param filename - name of the file where assembler code located
 * @return Operation result
 */
int ArithmeticLogicUnit::translateASM(const std::string& filename)
{
    std::ifstream in;
    in.open(filename);
    if (in.is_open()) {
        if (in.good()) {
            std::string strLine;                       // line in file
            while (std::getline(in, strLine)) {        // while eof
                std::istringstream strStream(strLine); // get piece of line
                int number, commandNumber;             // command number
                strStream >> number;                   // get number of command
                std::string command;                   // asm command
                strStream >> command;                  // get command
                int operand;                           // asm operand
                strStream >> operand;                  // get asm operand
                if (command == "READ") {               // is READ?
                    commandNumber = 0x10;
                } else if (command == "WRITE") { // is WRITE?
                    commandNumber = 0x11;
                } else if (command == "LOAD") { // is LOAD?
                    commandNumber = 0x20;
                } else if (command == "STORE") { // is STORE?
                    commandNumber = 0x21;
                } else if (command == "ADD") { // is ADD?
                    commandNumber = 0x30;
                } else if (command == "SUB") { // is SUB?
                    commandNumber = 0x31;
                } else if (command == "DIVIDE") { // is DIVIDE?
                    commandNumber = 0x32;
                } else if (command == "MUL") { // is MUL?
                    commandNumber = 0x33;
                } else if (command == "JUMP") { // is JUMP?
                    commandNumber = 0x40;
                } else if (command == "JNEG") { // is JNEG?
                    commandNumber = 0x41;
                } else if (command == "JZ") { // is JZ?
                    commandNumber = 0x42;
                } else if (command == "HALT") { // is HALT?
                    if (operand != 0) {
                        return -1;
                    }
                    commandNumber = 0x43;
                } else if (command == "JNC") { // is JNC?
                    commandNumber = 0x57;
                } else // something else
                    return -1;
                int value; // contain encoded command
                encodeCommand(commandNumber, operand, value); // form a command
                memorySet(number, value); // loads into memory
            }
            return 0;
        }
    }
    return -1;
}