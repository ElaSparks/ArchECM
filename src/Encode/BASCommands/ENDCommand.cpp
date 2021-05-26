#include "../../../include/ArithmeticLogicUnit.h"
/**
 * Broadcasting the END Command. Converting into HALT asm command.
 * @param startAt - the line number with which the broadcast will begin
 * @return Broadcast result
 */
std::string ArithmeticLogicUnit::commandEND(int& startAt)
{
    std::stringstream result;
    result << std::setw(2) << std::setfill('0') << startAt++;
    result << " HALT 00\n";
    return result.str();
}