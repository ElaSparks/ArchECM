#include "../../include/MySimpleComputer.h"
/**
 * Draw all GUI of the simple computer
 * @file GUIALL.cpp
 * @return A value indicating the result of an attempt to render all GUI
 * elements
 */
int MySimpleComputer::DrawAll()
{
    setScreenSize(25, 84); // resize terminal
    int error = 0;         // Errors indicator
    cleanScreen();         // clean screen
    error += DrawBigChar();
    error += DrawFrames();
    error += DrawNames();
    error += DrawInstruction();
    error += DrawFlags();
    error += DrawMemory();
    error += DrawAccumulator();
    error += DrawOperation();
    move(24, 0);     // move cursor under frame
    if (error < 0) { // check for errors
        return -1;
    }
    return 0;
}