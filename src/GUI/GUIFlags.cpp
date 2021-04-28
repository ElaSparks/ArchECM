#include "../../include/MySimpleComputer.h"
/**
 * The function draws on the screen the contents of the flags register
 * @file GUIFlags.cpp
 * @return Operation result
 */
int MySimpleComputer::DrawFlags()
{
    int error = 0;
    int value = 0;
    std::string flagNames = "OZMIW";
    for (int i = 0; i < flagNames.length(); ++i) {
        error += move(11, 68 + 2 * i);
        registerGet(i + 1, value);
        if (value) {
            setBackgroundColor(Red);
        } else {
            setBackgroundColor(Reset);
        }
        printf("%c", flagNames[i]);
    }
    setBackgroundColor(Reset);
    if (error < 0) {
        return -1;
    }
    return 0;
}