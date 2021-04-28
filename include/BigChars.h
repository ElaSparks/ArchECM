#ifndef BIGCHARS_H
#define BIGCHARS_H
#include "TermDesign.h"
#include <cctype>
#include <fcntl.h>
#include <string>
#include <unistd.h>

/**
 * A small library designed to map to ordinary characters, pseudo-graphic
 * equivalent
 */
class BigChars : protected TermDesign {
protected:
    void printASC(const std::string& str);
    int printFrame(int x, int y, int height, int width);
    int printBigChar(
            unsigned long long symbol,
            int x,
            int y,
            colors color,
            colors backgroundColor);
    unsigned long long initBigChar(char value);
};

#endif
