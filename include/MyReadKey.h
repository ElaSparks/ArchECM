#ifndef MYREADKEY_H
#define MYREADKEY_H

#include <cstring>
#include <termios.h>
#include <unistd.h>
/**
 * An enumeration containing all the keys used
 */
enum keys {
    key_up,
    key_down,
    key_right,
    key_left,
    key_load,
    key_save,
    key_run,
    key_step,
    key_reset,
    key_enter,
    key_f5,
    key_f6,
    key_quit,
    key_other
};
/**
 * Small library responsible for working with terminal modes.
 */
class MyReadKey {
private:
    termios mySettings{}; // to store my current settings
    int saveTerminalSettings();
    int restoreTerminalSettings();
    int
    switchTerminalRegime(int regime, int vtime, int vmin, int echo, int sigint);

protected:
    int readKey(enum keys& key);
    int switchEcho();
};

#endif
