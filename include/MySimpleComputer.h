#ifndef MYSIMPLECOMPUTER_H
#define MYSIMPLECOMPUTER_H

#include "ArithmeticLogicUnit.h"
#include "BigChars.h"

class MySimpleComputer : protected BigChars, protected ArithmeticLogicUnit {
private:
    int selector = 0;                               // user cursor
    void sc_regInit();                              // clean registers
    void sc_memoryInit();                           // clean memory
    void sc_accumulatorInit();                      // clean accumulator
    int sc_memorySave(const std::string& filename); // save ram in file
    int sc_memoryLoad(const std::string& filename); // load ram from file
    // gui
    int DrawAll();
    int DrawFrames();      // Print all frames
    int DrawNames();       // Print names of frame and another text
    int DrawInstruction(); // Print number of execute command
    int DrawMemory();      // Print values which ram contain
    int DrawFlags();       // Print flags value
    int DrawBigChar();     // Print big char
    int DrawAccumulator(); // Print value which accumulator contain
    int DrawOperation();   // Print encoded operation
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
