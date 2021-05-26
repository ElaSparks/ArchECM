#include "../../../include/ArithmeticLogicUnit.h"
/**
 * The function fills in the addresses referenced by IF and GOTO.
 * @param result - String containing the translation result
 * @param compare - A vector that stores the correspondence between assembler
 * and basic code
 * @return Operation result
 */
int ArithmeticLogicUnit::compareGOTO(
        std::string& result, const std::vector<int>& compare)
{
    for (int i = 0; i < compare.size(); ++i) {
        replace(result,
                "?" + std::to_string((i + 1) * 10),
                std::to_string(compare[i]));
    }
    if (result.find('?') == -1)
        return 0;
    else
        return -1;
}