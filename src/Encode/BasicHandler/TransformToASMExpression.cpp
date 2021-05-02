#include "../../../include/ArithmeticLogicUnit.h"
std::string ArithmeticLogicUnit::transformToASMExpression(
        std::queue<std::string> rpn, int& startAt)
{
    int stack = 0;
    std::string result;
    while (!rpn.empty()) {
        std::string token = rpn.front();
        rpn.pop();

        if (getPriority(token[0]) >= 0) {
            std::stringstream ss;
            ss << std::setw(2) << std::setfill('0') << startAt++;
            result.append(ss.str() + " ");
            ss.str(std::string());
            ss.clear();
            result.append("LOAD $");
            result.append(std::to_string(--stack - 1) + "\n");
            if (token == "+") {
                ss << std::setw(2) << std::setfill('0') << startAt++;
                result.append(ss.str() + " ");
                ss.str(std::string());
                ss.clear();
                result.append("ADD $");
                result.append(std::to_string(stack--) + "\n");
            } else if (token == "*") {
                ss << std::setw(2) << std::setfill('0') << startAt++;
                result.append(ss.str() + " ");
                ss.str(std::string());
                ss.clear();
                result.append("MUL $");
                result.append(std::to_string(stack--) + "\n");
            } else if (token == "-") {
                ss << std::setw(2) << std::setfill('0') << startAt++;
                result.append(ss.str() + " ");
                ss.str(std::string());
                ss.clear();
                result.append("SUB $");
                result.append(std::to_string(stack--) + "\n");
            } else if (token == "/") {
                ss << std::setw(2) << std::setfill('0') << startAt++;
                result.append(ss.str() + " ");
                ss.str(std::string());
                ss.clear();
                result.append("DEVIDE $");
                result.append(std::to_string(stack--) + "\n");
            }

            ss << std::setw(2) << std::setfill('0') << startAt++;
            result.append(ss.str() + " ");
            ss.str(std::string());
            ss.clear();
            result.append("STORE $");
            result.append(std::to_string(stack++) + "\n");

        } else {
            int address = letterAddress(token[0]);
            std::stringstream ss;
            ss << std::setw(2) << std::setfill('0') << startAt++;
            result.append(ss.str() + " ");
            ss.str(std::string());
            ss.clear();
            result.append("LOAD " + std::to_string(address) + "\n");

            ss << std::setw(2) << std::setfill('0') << startAt++;
            result.append(ss.str() + " ");
            ss.str(std::string());
            ss.clear();
            result.append("STORE $");
            result.append(std::to_string(stack++) + "\n");
        }
    }

    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << startAt++;
    result.append(ss.str() + " ");
    ss.str(std::string());
    ss.clear();
    result.append("LOAD $" + std::to_string(--stack) + "\n");

    return result;
}