#include "../../include/MySimpleComputer.h"
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