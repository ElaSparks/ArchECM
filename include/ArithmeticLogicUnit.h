#ifndef ALU_H
#define ALU_H
#define OVERFLOW 1
#define DIVISION_BY_ZERO 2
#define OUT_OF_MEMORY 3
#define IGNORE_IMPULSE 4
#define WRONG_COMMAND 5
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
class ArithmeticLogicUnit : protected MyReadKey {
private:
    void commandRead(int operand);   // read from console into mem
    void commandWrite(int operand);  // output mem value
    void commandLoad(int operand);   // from mem to acc
    void commandStore(int operand);  // from acc to mem
    void commandAdd(int operand);    // acc+mem
    void commandSub(int operand);    // acc-mem
    void commandDivide(int operand); // acc/mem
    void commandMul(int operand);    // acc*mem
    void commandJump(int operand);   // goto
    void commandJNEG(int operand);   // goto acc<0
    void commandJZ(int operand);     // goto acc==0
    void commandJNC(int operand);    // goto OVERFLOW==0
    void commandHalt(int operand);   // stop + goto zero mem pos

protected:
    int memory[100]{};                   // ram of the computer
    int accumulator{};                   // result of operation
    bool jump = false;                   // flag jump
    std::bitset<5> flags{};              // flags from current operation
    std::bitset<5> flagsLO{};            // flags from last operation
    int instructionCounter = 0;          // number of the running command
    const std::vector<int> commands;     // all commands of assembler
    struct itimerval newTimer, oldTimer; // iteration call timers

    int sc_regSet(int reg, int value);         // set registers
    int sc_regGet(int reg, int& value);        // get registers
    int sc_accumulatorSet(int value);          // set accumulator value
    int sc_instructionCounterSet(int address); // set iC value
    int sc_memorySet(int address, int value);  // set mem value
    int sc_memoryGet(int address, int& value); // get mem value
    int encodeCommand(int command, int operand, int& value);
    int decodeCommand(int value, int& command, int& operand);

    void ALU(int command, int operand);
    void controlUnit();
    int letterMemory(char symbol);
    std::vector<int> juxtaposeCode(const std::string& filename);
    int translateASM(const std::string& filename);
    int translateBAS(const std::string& filename);

public:
    ArithmeticLogicUnit();
};

#endif