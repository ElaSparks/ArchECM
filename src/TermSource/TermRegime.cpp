#include "../../include/MyReadKey.h"
int MyReadKey::switchTerminalRegime(
        int regime,
        int vtime,
        int vmin,
        int echo,
        int sigint) // the function is designed to change the operating mode of
                    // the terminal
{
    termios termSettings{};
    if (tcgetattr(0, &termSettings) != 0) {
        return -1; // if you can't read the settings for the terminal
    }

    if (regime == 1) { // change settings
        termSettings.c_lflag |= ICANON;
    } else if (regime == 0) {
        termSettings.c_lflag &= ~ICANON;

        termSettings.c_cc[VTIME] = vtime;
        termSettings.c_cc[VMIN] = vmin;

        if (echo == 1) {
            termSettings.c_lflag |= ECHO;
        } else if (echo == 0) {
            termSettings.c_lflag &= ~ECHO;
        }
        if (sigint == 1) {
            termSettings.c_lflag |= ISIG;
        } else if (sigint == 0) {
            termSettings.c_lflag &= ~ISIG;
        }
    }
    if (tcsetattr(0, TCSANOW, &termSettings) != 0) {
        return -1; // if it failed to set new settings for the terminal
    }
    return 0;
}