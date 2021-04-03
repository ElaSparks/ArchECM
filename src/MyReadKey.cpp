#include "../include/MyReadKey.h"
int MyReadKey::rk_readkey(keys& key) // reads a keystroke
{
    rk_mytermsave();
    rk_mytermregime(0, 0, 1, 0, 1);
    char buf[8] = {0};
    read(STDIN_FILENO, buf, 8);
    rk_mytermrestore();
    if (strcmp(buf, "\E[A") == 0)
        key = key_up;
    else if (strcmp(buf, "\E[B") == 0)
        key = key_down;
    else if (strcmp(buf, "\E[C") == 0)
        key = key_right;
    else if (strcmp(buf, "\E[D") == 0)
        key = key_left;
    else if (strcmp(buf, "\E[15~") == 0)
        key = key_f5;
    else if (strcmp(buf, "\E[17~") == 0)
        key = key_f6;
    else if (buf[0] == 'l')
        key = key_load;
    else if (buf[0] == 's')
        key = key_save;
    else if (buf[0] == 'r')
        key = key_run;
    else if (buf[0] == 't')
        key = key_step;
    else if (buf[0] == 'i')
        key = key_reset;
    else if (buf[0] == 'q')
        key = key_quit;
    else
        key = key_other;
    return 0;
}
