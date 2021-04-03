#ifndef MYBIGCHARS_H
#define MYBIGCHARS_H
#include "MyTerm.h"
#include <cctype>
#include <fcntl.h>
#include <string>
#include <unistd.h>

class MyBigChars : protected MyTerm {
protected:
    void bc_printA(const std::string& str);
    int bc_box(int x, int y, int height, int width);
    int bc_printbigchar(
            unsigned long long symbol,
            int x,
            int y,
            colors color,
            colors backgroundColor);
    unsigned long long bc_initbigchar(char value);
};

#endif
