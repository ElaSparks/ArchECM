#ifndef MYSIMPLECOMPUTER_H
#define MYSIMPLECOMPUTER_H
#define OVERFLOW 1
#define DIVISION_BY_ZERO 2
#define OUT_OF_MEMORY 3
#define IGNORE_IMPULS 4
#define WRONG_COMMAND 5

#include "MyBigChars.h"
#include "MyReadKey.h"
#include <bits/stdc++.h>
#include <fstream>
#include <signal.h>
#include <sys/time.h>

class MySimpleComputer : protected MyBigChars, protected MyReadKey {
private:
    std::bitset<15> memory[100]{}; // ram of the computer
    std::bitset<15> accumulator{}; // result of operation
    std::bitset<5> flags{};
    int instructionCounter = 0;      // number of the running command
    const std::vector<int> commands; // all commands of assembler
    void sc_regInit();
    void sc_memoryInit();
    int sc_regSet(int reg, int value);
    int sc_regGet(int reg, int& value);
    int sc_memorySet(int address, int value);
    int sc_memoryGet(int address, int& value);
    int sc_memorySave(const std::string& filename); // save ram in file
    int sc_memoryLoad(const std::string& filename); // load ram from file
    int sc_commandEncode(int command, int operand, int& value);
    int sc_commandDecode(int value, int& command, int& operand);
    // gui
    int DrawAll();         // Print all gui elements
    int DrawFrames();      // Print all frames
    int DrawNames();       // Print names of frame and another text
    int DrawInstruction(); // Print number of execute command
    int DrawMemory();      // Print values which ram contain
    int DrawFlags();       // Print flags value
    int DrawBigChar();     // Print big char
    int DrawAccumulator(); // Print value which accumulator contain
    int DrawOperation();   // Print encoded operation
    // signals
    struct itimerval newTimer, oldTimer;
    static void stopHandler(int signal);
    static void runHandler(int signal);
    void oneStep();
    void runEachMemory();

public:
    MySimpleComputer();
    void runComputer();
};

#endif
