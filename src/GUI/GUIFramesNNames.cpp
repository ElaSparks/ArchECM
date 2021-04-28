#include "../../include/MySimpleComputer.h"
int MySimpleComputer::DrawFrames()
{
    int error = 0;
    error += printFrame(1, 1, 12, 61);
    error += printFrame(1, 62, 3, 20);
    error += printFrame(4, 62, 3, 20);
    error += printFrame(7, 62, 3, 20);
    error += printFrame(10, 62, 3, 20);
    error += printFrame(13, 1, 10, 46);
    error += printFrame(13, 47, 10, 35);
    if (error < 0) {
        return -1;
    }
    return 0;
}
int MySimpleComputer::DrawNames()
{
    int error = 0;
    error += move(1, 29);
    printf("Memory");
    error += move(1, 67);
    printf("Accumulator");
    error += move(4, 63);
    printf("InstructionCounter");
    error += move(7, 68);
    printf("Operation");
    error += move(10, 70);
    printf("Flags");
    error += move(13, 48);
    printf("Keys:");
    error += move(14, 48);
    printf("l  - load");
    error += move(15, 48);
    printf("s  - save");
    error += move(16, 48);
    printf("r  - run");
    error += move(17, 48);
    printf("t  - step");
    error += move(18, 48);
    printf("i  - reset");
    error += move(19, 48);
    printf("F5 - accumulator");
    error += move(20, 48);
    printf("F6 - instruction counter");
    if (error < 0) {
        return -1;
    }
    return 0;
}