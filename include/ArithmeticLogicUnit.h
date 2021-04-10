#ifndef ALU_H
#define ALU_H
#define OVERFLOW 1
#define DIVISION_BY_ZERO 2
#define OUT_OF_MEMORY 3
#define IGNORE_IMPULS 4
#define WRONG_COMMAND 5

#include <bits/stdc++.h>

class ArithmeticLogicUnit {
private:
    int commandRead(int operand);
    int commandWrite(int operand);
    int commandLoad(int operand);
    int commandStore(int operand);
    int commandAdd(int operand);
    int commandSub(int operand);
    int commandDivide(int operand);
    int commandMul(int operand);
    int commandJump(int operand);
    int commandJNEG(int operand);
    int commandJZ(int operand);
    int commandHalt();
    int commandJNC(int operand);

protected:
    short memory[100]{}; // ram of the computer
    short accumulator{}; // result of operation
    std::bitset<5> flags{};
    int instructionCounter = 0;        // number of the running command
    const std::vector<short> commands; // all commands of assembler

    int sc_regSet(int reg, int value);
    int sc_regGet(int reg, int& value);
    int sc_accumulatorSet(short value);
    int sc_memorySet(int address, short value);
    int sc_memoryGet(int address, int& value);
    int encodeCommand(int command, int operand, int& value);
    int decodeCommand(int value, int& command, int& operand);

    int ALU(int command, int operand);
    int controlUnit();
    int translate();

public:
    ArithmeticLogicUnit();
};

#endif