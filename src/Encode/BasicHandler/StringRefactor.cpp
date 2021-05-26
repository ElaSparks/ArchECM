#include "../../../include/ArithmeticLogicUnit.h"
/**
 * Function replace string or symbol to another string or symbol.
 * @file StringRefactor.cpp
 * @param str - the line we`re working on
 * @param from - symbol(s) which we want to replace
 * @param to - replacement symbol(s)
 */
void ArithmeticLogicUnit::replace(
        std::string& str, const std::string& from, const std::string& to)
{
    if (from.empty())
        return;
    int startPos = 0;
    while ((startPos = str.find(from, startPos)) != std::string::npos) {
        str.replace(startPos, from.length(), to);
        startPos += to.length();
    }
}
/**
 * Function delete all spaces in string. This function use for simplify
 * expression.
 * @file StringRefactor.cpp
 * @param line - string where we need delete the spaces
 */
void ArithmeticLogicUnit::deleteAllSpaces(std::string& line)
{
    while (strchr(" ", line[0]))
        line.erase(line.begin(), line.begin() + 1);
}