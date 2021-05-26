#include "../../include/MyReadKey.h"
/**
 * Function is need for save the settings, before reading the symbol.
 * @file TermSaveNRestore.cpp
 * @return Operation result
 */
int MyReadKey::saveTerminalSettings()
{
    if (tcgetattr(0, &mySettings) != 0) {
        return -1;
    }
    return 0;
}
/**
 * Function is need for restore original settings, after reading.
 * @file TermSaveNRestore.cpp
 * @return Operation result
 */
int MyReadKey::restoreTerminalSettings()
{
    if (tcsetattr(0, TCSANOW, &mySettings) != 0) {
        return -1;
    }
    return 0;
}