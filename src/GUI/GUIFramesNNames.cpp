#include "../../include/MySimpleComputer.h"
int MySimpleComputer::DrawFrames()
{
    int error = 0;
    error += bc_box(1, 1, 12, 61);
    error += bc_box(1, 62, 3, 20);
    error += bc_box(4, 62, 3, 20);
    error += bc_box(7, 62, 3, 20);
    error += bc_box(10, 62, 3, 20);
    error += bc_box(13, 1, 10, 46);
    error += bc_box(13, 47, 10, 35);
    if (error < 0) {
        return -1;
    }
    return 0;
}
int MySimpleComputer::DrawNames()
{
    int error = 0;
    error += mt_gotoXY(1, 29);
    printf("Memory");
    error += mt_gotoXY(1, 67);
    printf("Accumulator");
    error += mt_gotoXY(4, 63);
    printf("InstructionCounter");
    error += mt_gotoXY(7, 68);
    printf("Operation");
    error += mt_gotoXY(10, 70);
    printf("Flags");
    error += mt_gotoXY(13, 48);
    printf("Keys:");
    error += mt_gotoXY(14, 48);
    printf("l  - load");
    error += mt_gotoXY(15, 48);
    printf("s  - save");
    error += mt_gotoXY(16, 48);
    printf("r  - run");
    error += mt_gotoXY(17, 48);
    printf("t  - step");
    error += mt_gotoXY(18, 48);
    printf("i  - reset");
    error += mt_gotoXY(19, 48);
    printf("F5 - accumulator");
    error += mt_gotoXY(20, 48);
    printf("F6 - instruction counter");
    if (error < 0) {
        return -1;
    }
    return 0;
}