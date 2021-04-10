#include "../include/MySimpleComputer.h"

void MySimpleComputer::runComputer()
{
    keys key{};
    setbuf(stdout, nullptr);
    int impulse = 1;
    sc_regSet(IGNORE_IMPULS, 1);
    DrawAll();
    while (key != key_quit) {
        sc_regGet(IGNORE_IMPULS, impulse);
        if (impulse == 1) {
            rk_readkey(key);
            switch (key) {
            case key_load:
                sc_memoryLoad("memory.txt");
                break;
            case key_save:
                sc_memorySave("memory.txt");
                break;
            case key_reset:
                signal(SIGUSR1, stopHandler);
                raise(SIGUSR1);
                sc_memoryInit();
                sc_regInit();
                sc_accumulatorInit();
                sc_regSet(IGNORE_IMPULS, 1);
                break;
            case key_up:
                if (instructionCounter / 10 == 0) {
                    instructionCounter += 90;
                } else {
                    instructionCounter -= 10;
                }
                break;
            case key_down:
                if (instructionCounter / 10 == 9) {
                    instructionCounter -= 90;
                } else {
                    instructionCounter += 10;
                }
                break;
            case key_left:
                if (instructionCounter == 0) {
                    instructionCounter = 99;
                } else {
                    --instructionCounter;
                }
                break;
            case key_right:
                if (instructionCounter == 99) {
                    instructionCounter = 0;
                } else {
                    ++instructionCounter;
                }
                break;
            case key_run:

                runEachMemory();
                break;
            case key_step:
                oneStep();
                break;
            case key_enter: {
                short value = 0;
                std::cout << "Value of memory: ";
                std::cin >> value;
                sc_memorySet(instructionCounter, value);
                break;
            }
            case key_f5: {
                short value = 0;
                std::cout << "Value of accumulator: ";
                std::cin >> value;
                sc_accumulatorSet(value);
                break;
            }
            case key_f6:
                break;
            case key_quit:
                mt_clrscr();
                continue;
            case key_other:
                break;
            }
            DrawAll();
        }
    }
}