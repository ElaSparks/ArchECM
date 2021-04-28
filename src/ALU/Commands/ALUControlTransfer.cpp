#include "../../../include/ArithmeticLogicUnit.h"
/**
 * Broadcasting the JUMP Command. Go to the specified memory address
 * @file ALUControlTransfer.cpp
 * @param operand - memory address
 */
void ArithmeticLogicUnit::commandJump(int operand)
{
    instructionCounterSet(operand);
    jump = true;
}
/**
 * Broadcasting the JNEG Command. Jump to the specified memory address if the
 * accumulator contains a negative number
 * @file ALUControlTransfer.cpp
 * @param operand - memory address
 */
void ArithmeticLogicUnit::commandJNEG(int operand)
{
    if (accumulator < 0) {
        instructionCounterSet(operand);
        jump = true;
    }
}
/**
 * Broadcasting the JZ Command. Jump to the specified memory address if there is
 * zero in the accumulator
 * @file ALUControlTransfer.cpp
 * @param operand - memory address
 */
void ArithmeticLogicUnit::commandJZ(int operand)
{
    if (accumulator == 0) {
        instructionCounterSet(operand);
        jump = true;
    }
}
/**
 * Broadcasting the JNC Command. Jump to the specified memory address if the
 * addition did not overflow
 * @file ALUControlTransfer.cpp
 * @param operand - memory address
 */
void ArithmeticLogicUnit::commandJNC(int operand)
{
    if (flagsLO[OVERFLOW - 1] == 0) {
        instructionCounterSet(operand);
        jump = true;
    }
}
/**
 * Broadcasting the HALT Command. Stop, executed when the program terminates
 * @file ALUControlTransfer.cpp
 * @param operand - memory address (default = 00)
 */
void ArithmeticLogicUnit::commandHalt(int operand)
{
    registerSet(IGNORE_IMPULSE, 1);
    instructionCounterSet(operand);
    jump = true;
}
