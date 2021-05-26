#include "../../../include/ArithmeticLogicUnit.h"
/**
 * Function parse complex expression and broadcast into asm code reference.
 * @file ParseLET.cpp
 * @param line - a line of basic code. Added to the function to parse the
 * expression
 * @param startAt - the line number with which the broadcast will begin
 * @return Broadcast result
 */
std::string ArithmeticLogicUnit::parseLET(std::string line, int& startAt)
{
    std::string translated;
    line.erase(line.begin(), line.begin() + line.find("LET") + 3);
    deleteAllSpaces(line);
    int dest = letterAddress(line[0]);
    if (dest == -1)
        return std::string{};
    line = line.substr(line.find('=') + 1);
    char buffer[line.length()];
    strcpy(buffer, line.c_str());
    auto rpn = setTokensQueue(buffer);
    translated.append(transformToASMExpression(rpn, startAt));
    translated.append(std::to_string(startAt++) + " ");
    translated.append("STORE ").append(std::to_string(dest));
    if (translated[translated.length() - 1] != '\n')
        translated.append("\n");
    return translated;
}