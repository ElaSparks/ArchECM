#include "../../../include/ArithmeticLogicUnit.h"
/**
 * Broadcasting the GOTO Command. Converting into JUMP asm command. The address
 * in temporarily presented in the format '?(address in basic)'
 * @param line - a line of basic code. Added to the function to parse the
 * address
 * @param startAt - the line number with which the broadcast will begin
 * @return Broadcast result
 */
std::string
ArithmeticLogicUnit::commandGOTO(const std::string& line, int& startAt)
{
    std::stringstream ss(line.substr(line.find("GOTO ") + 5));
    int address;
    ss >> address;
    std::stringstream result;
    result << std::setw(2) << std::setfill('0') << startAt++;
    result << " JUMP ?" << address << "\n";
    return result.str();
}