#include "../../../include/ArithmeticLogicUnit.h"
std::queue<std::string> ArithmeticLogicUnit::setTokensQueue(char* expr)
{
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::queue<std::string> tokens;
    std::stack<char> operators;
    while (*expr) {
        if (*expr == ' ' || *expr == '\t') {
            expr++;
            continue;
        } else if (alphabet.find(*expr) != -1) {
            int length = 0;
            while (expr[length] && alphabet.find(expr[length]) != -1)
                length++;

            tokens.push(std::string(expr, length));
            expr += length;
        } else {
            switch (*expr) {
            case '(':
                operators.push('(');
                expr++;
                break;
            case ')':
                while (operators.top() != '(') {
                    tokens.push(std::string(1, operators.top()));
                    operators.pop();
                }
                operators.pop();
                expr++;
                break;
            default: {
                while (!operators.empty()
                       && getPriority(operators.top()) >= getPriority(*expr)) {
                    tokens.push(std::string(1, operators.top()));
                    operators.pop();
                }
                operators.push(*expr);
                expr++;
            }
            }
        }
    }

    while (!operators.empty()) {
        tokens.push(std::string(1, operators.top()));
        operators.pop();
    }

    return tokens;
}
