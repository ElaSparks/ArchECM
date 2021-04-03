#include "../../include/MySimpleComputer.h"
int MySimpleComputer::DrawAll()
{
    mt_setscreensize(25, 84);
    int error = 0;
    mt_clrscr();
    error += DrawBigChar();
    error += DrawFrames();
    error += DrawNames();
    error += DrawInstruction();
    error += DrawFlags();
    error += DrawMemory();
    mt_gotoXY(24, 0);
    if (error < 0) {
        return -1;
    }
    return 0;
}