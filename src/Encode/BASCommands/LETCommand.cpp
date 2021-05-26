#include "../../../include/ArithmeticLogicUnit.h"
/**
 * Broadcasting the LET Command. This function parse the expression end convert
 * them into assembler reference.
 * @param line - a line of basic code. Added to the function to parse the
 * expression
 * @param startAt - the line number with which the broadcast will begin
 * @return Broadcast result
 */
std::string
ArithmeticLogicUnit::commandLET(const std::string& line, int& startAt)
{
    if (line.find(" + ") == -1 && line.find(" - ") == -1
        && line.find(" * ") == -1 && line.find(" / ") == -1) {
        std::stringstream result;
        char destinationLetter = line[line.find("LET ") + 4];
        int destination = letterAddress(destinationLetter);
        if (destination == -1)
            return std::string{};
        char equalLetter = line[line.find(" = ") + 3];
        int equal = letterAddress(equalLetter);
        result << std::setw(2) << std::setfill('0') << startAt++;
        if (equal == -1) {
            std::stringstream ss(line.substr(line.find(" = ") + 3));
            int value;
            ss >> value;
            result << " MOVEAX " << value << "\n";
        } else {
            result << " LOAD " << equal << "\n";
        }
        result << std::setw(2) << std::setfill('0') << startAt++;
        result << " STORE " << destination << "\n";
        return result.str();
    } else {
        std::string translated = parseLET(line, startAt);
        if (translated.empty())
            return std::string{};
        for (int i = 0, pos = dataAddress - 26; i < dataAddress - 26;
             ++i, --pos) {
            replace(translated, "$" + std::to_string(i), std::to_string(pos));
        }
        return translated;
    }
}