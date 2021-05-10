#include "../include/MySimpleComputer.h"
/**
 * The main function of a simple computer, which interacts with the user and
 * processes his actions
 * @file MainActivity.cpp
 */
void MySimpleComputer::runComputer()
{
    keys key{};
    setbuf(stdout, nullptr);              // disable the buffer at printf
    int impulse = 1;                      // contain impulse register value
    registerSet(IGNORE_IMPULSE, impulse); // set initial value
    DrawAll();                            // draw all interface
    while (key != key_quit) {             // while quit button isn`t pressed
        registerGet(IGNORE_IMPULSE, impulse);
        if (impulse == 1) {
            rk_readkey(key);
            switch (key) {
            case key_load: {
                std::string value;
                int expect = 1;
                std::cout << "Load. File name + file extension: ";
                std::cin >> value;
                if (value.substr(value.length() - 3, 3) == "asm") {
                    expect = translateASM(value);
                } else if (value.substr(value.length() - 3, 3) == "bas") {
                    expect = translateBAS(value);
                } else if (value.substr(value.length() - 2, 2) == ".o") {
                    expect = memoryLoad(value);
                } else {
                    memoryInit();
                    std::cout << "Incorrect file format!" << std::endl;
                }
                if (expect == -1) {
                    std::cout << "Error" << std::endl;
                } else if (expect == 0) {
                    std::cout << "Successful" << std::endl;
                }
                std::cout << "Press enter key to continue..." << std::endl;
                std::cin.ignore(
                        std::numeric_limits<std::streamsize>::max(), '\n');
                getchar();
                registerInit();
                accumulatorInit();
                instructionCounter = 0;
                registerSet(IGNORE_IMPULSE, 1);
                break;
            }
            case key_save: {
                std::string value;
                std::cout << "Saving. File name: ";
                std::cin >> value;
                memorySave(value + ".o");
                break;
            }
            case key_reset:
                signal(SIGUSR1, stopHandler);
                raise(SIGUSR1);
                memoryInit();
                registerInit();
                accumulatorInit();
                instructionCounterSet(0);
                registerSet(IGNORE_IMPULSE, 1);
                break;
            case key_up:
                if (selector / 10 == 0) {
                    selector += 90;
                } else {
                    selector -= 10;
                }
                break;
            case key_down:
                if (selector / 10 == 9) {
                    selector -= 90;
                } else {
                    selector += 10;
                }
                break;
            case key_left:
                if (selector == 0) {
                    selector = 99;
                } else {
                    --selector;
                }
                break;
            case key_right:
                if (selector == 99) {
                    selector = 0;
                } else {
                    ++selector;
                }
                break;
            case key_run:
                runEachMemory();
                break;
            case key_step:
                oneStep();
                break;
            case key_enter: {
                int value = 0;
                std::cout << "Value of memory: ";
                std::cin >> value;
                memorySet(selector, value);
                break;
            }
            case key_f5: {
                int value = 0;
                std::cout << "Value of accumulator: ";
                std::cin >> value;
                accumulatorSet(value);
                break;
            }
            case key_f6: {
                int value = 0;
                std::cout << "InstructionCounter position: ";
                std::cin >> value;
                instructionCounterSet(value);
                break;
            }
            case key_quit:
                cleanScreen(); // together with shutdown, we clear the screen
                continue;
            case key_other: // other buttons are not processed
                break;
            }
            DrawAll();
        }
    }
}