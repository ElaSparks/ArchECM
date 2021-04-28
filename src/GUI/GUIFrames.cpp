#include "../../include/MySimpleComputer.h"
/**
 * The function renders all GUI frames
 * @file GUIFrames.cpp
 * @return Operation result
 */
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