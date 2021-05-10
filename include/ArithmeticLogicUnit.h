#ifndef ALU_H
#define ALU_H
#define OVERFLOW 1
#define DIVISION_BY_ZERO 2
#define OUT_OF_MEMORY 3
#define IGNORE_IMPULSE 4
#define WRONG_COMMAND 5
#define dataAddress 99
#define debug std::cout << "+++" << std::endl
#define inspect(x) std::cout << #x << "=" << x << std::endl;
#define breakpoint \
    getchar();     \
    getchar()

#include "MyReadKey.h"
#include <bits/stdc++.h>
#include <fstream>
#include <signal.h>
#include <sstream>
#include <sys/time.h>
/**
 * A class containing the main set of variables and functions that reflect the
 * structure of a computer, the principle of operation and interaction with a
 * computer at the physical level
 * @author ElaSparks
 */
class ArithmeticLogicUnit : protected MyReadKey {
private:
    void commandRead(int operand);
    void commandWrite(int operand);
    void commandLoad(int operand);
    void commandStore(int operand);
    void commandAdd(int operand);
    void commandSub(int operand);
    void commandDivide(int operand);
    void commandMul(int operand);
    void commandMOVEAX(int operand);
    void commandJump(int operand);
    void commandJNEG(int operand);
    void commandJZ(int operand);
    void commandJNC(int operand);
    void commandHalt(int operand);

    std::string commandIF(const std::string& line, int& startAt);
    std::string commandEND(int& startAt);
    std::string commandLET(const std::string& line, int& startAt);
    std::string commandGOTO(const std::string& line, int& startAt);
    std::string commandINPUT(const std::string& line, int& startAt);
    std::string commandOUTPUT(const std::string& line, int& startAt);

    int getPriority(int operation);
    int letterAddress(char symbol);
    void ALU(int command, int operand);
    void deleteAllSpaces(std::string& line);
    std::queue<std::string> setTokensQueue(char* str);
    std::string parseLET(std::string line, int& startAt);
    int compareGOTO(std::string& result, const std::vector<int>& compare);
    std::string
    transformToASMExpression(std::queue<std::string> rpn, int& startAt);
    void
    replace(std::string& str, const std::string& from, const std::string& to);

protected:
    int memory[100]{};                   // computer memory
    int accumulator{};                   // result of operation
    bool jump = false;                   // disable iteration if jump
    std::bitset<5> flags{};              // flags for current operation
    std::bitset<5> flagsLO{};            // flags for last operation
    int instructionCounter = 0;          // number of the running command
    const std::vector<int> commands;     // all commands of assembler
    struct itimerval newTimer, oldTimer; // iteration call timers

    int accumulatorSet(int value);
    int registerSet(int reg, int value);
    int registerGet(int reg, int& value);
    int memorySet(int address, int value);
    int memoryGet(int address, int& value);
    int instructionCounterSet(int address);
    int encodeCommand(int command, int operand, int& value);
    int decodeCommand(int value, int& command, int& operand);

    void controlUnit();
    int translateASM(const std::string& filename);
    int translateBAS(const std::string& filename);

public:
    ArithmeticLogicUnit();
};

#endif