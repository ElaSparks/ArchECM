#ifndef MYSIMPLECOMPUTER_H
#define MYSIMPLECOMPUTER_H

#include "ArithmeticLogicUnit.h"
#include "BigChars.h"

class MySimpleComputer : protected BigChars, protected ArithmeticLogicUnit {
private:
    int selector = 0; // position of user cursor
    void registerInit();
    void memoryInit();
    void accumulatorInit();
    int memorySave(const std::string& filename);
    int memoryLoad(const std::string& filename);
    // gui
    int DrawAll();
    int DrawFrames();
    int DrawNames();
    int DrawInstruction();
    int DrawMemory();
    int DrawFlags();
    int DrawBigChar();
    int DrawAccumulator();
    int DrawOperation();
    // signals
    static void stopHandler(int signal);
    static void runHandler(int signal);
    void oneStep();
    void runEachMemory();

public:
    MySimpleComputer();
    void runComputer();
};

#endif
