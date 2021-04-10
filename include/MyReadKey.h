#ifndef MYREADKEY_H
#define MYREADKEY_H

#include <cstring>
#include <termios.h>
#include <unistd.h>

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

class MyReadKey {
private:
    termios mySettings{}; // to store my current settings
    int rk_mytermsave();
    int rk_mytermrestore();
    int rk_mytermregime(int regime, int vtime, int vmin, int echo, int sigint);

protected:
    int rk_readkey(enum keys& key);
    int rk_switchecho();
};

#endif
