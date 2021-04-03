#include "../include/MyReadKey.h"
int MyReadKey::rk_mytermsave() // in order to temporarily save the settings
                               // before reading the symbol
{
    if (tcgetattr(0, &mySettings) != 0) {
        return -1;
    }
    return 0;
}
int MyReadKey::rk_mytermrestore() // restore original settings after reading
{
    if (tcsetattr(0, TCSANOW, &mySettings) != 0) {
        return -1;
    }
    return 0;
}