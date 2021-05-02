#include "../../../include/ArithmeticLogicUnit.h"
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