#include "../../include/MySimpleComputer.h"
/**
 * Function save memory content in binary(object) file.
 * @file SimpleComputerMemory.cpp
 * @param filename - output file name
 * @return Operation result
 */
int MySimpleComputer::memorySave(const std::string& filename)
{
    std::ofstream output(filename, std::ios::out | std::ios::binary);
    if (output.is_open()) {
        if (output.good()) {
            output.write((char*)memory, sizeof(memory));
            return 0;
        }
    }
    return -1;
}
/**
 * Function load content binary(object) file in memory.
 * @file SimpleComputerMemory.cpp
 * @param filename - input file name
 * @return Operation result
 */
int MySimpleComputer::memoryLoad(const std::string& filename)
{
    std::ifstream input(filename, std::ios::in | std::ios::binary);
    if (input.is_open()) {
        if (input.good()) {
            input.read((char*)memory, sizeof(memory));
            return 0;
        }
    }
    return -1;
}