#ifndef ALU_H
#define ALU_H
#define OVERFLOW 1
#define DIVISION_BY_ZERO 2
#define OUT_OF_MEMORY 3
#define IGNORE_IMPULS 4
#define WRONG_COMMAND 5

#include "MyReadKey.h"
#include <bits/stdc++.h>
#include <signal.h>
#include <sys/time.h>

class ArithmeticLogicUnit : protected MyReadKey {
private:
    int commandRead(int operand);   // read from console into mem
    int commandWrite(int operand);  // output mem value
    int commandLoad(int operand);   // from mem to acc
    int commandStore(int operand);  // from acc to mem
    int commandAdd(int operand);    // acc+mem
    int commandSub(int operand);    // acc-mem
    int commandDivide(int operand); // acc/mem
    int commandMul(int operand);    // acc*mem
    int commandJump(int operand);   // goto
    int commandJNEG(int operand);   // goto acc<0
    int commandJZ(int operand);     // goto acc==0
    int commandJNC(int operand);    // goto OVERFLOW==0
    int commandHalt();              // stop + goto zero mem pos

protected:
    short memory[100]{};                 // ram of the computer
    short accumulator{};                 // result of operation
    std::bitset<5> flags{};              // flags from current operation
    std::bitset<5> flagsLO{};            // flags from last operation
    int instructionCounter = 0;          // number of the running command
    const std::vector<short> commands;   // all commands of assembler
    struct itimerval newTimer, oldTimer; // iteration call timers

    int sc_regSet(int reg, int value);           // set registers
    int sc_regGet(int reg, int& value);          // get registers
    int sc_accumulatorSet(short value);          // set accumulator value
    int sc_instructionCounterSet(short address); // set iC value
    int sc_memorySet(int address, short value);  // set mem value
    int sc_memoryGet(int address, short& value); // get mem value
    int encodeCommand(int command, int operand, int& value);
    int decodeCommand(int value, int& command, int& operand);

    int ALU(int command, int operand);
    int controlUnit();
    int translate();

public:
    ArithmeticLogicUnit();
};

#endif