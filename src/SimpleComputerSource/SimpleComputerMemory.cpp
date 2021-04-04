#include "../../include/MySimpleComputer.h"
int MySimpleComputer::sc_memorySet(int address, int value)
{
    if ((address >= 0) && (address <= 99)) {
        memory[address] = value;
        return 0;
    }
    sc_regSet(OUT_OF_MEMORY, 1);
    return -1;
}
int MySimpleComputer::sc_memoryGet(int address, int& value)
{
    if ((address >= 0) && (address <= 99)) {
        value = (int)memory[address].to_ulong();
        return 0;
    }
    sc_regSet(OUT_OF_MEMORY, 1);
    return -1;
}
int MySimpleComputer::sc_memorySave(const std::string& filename)
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
int MySimpleComputer::sc_memoryLoad(const std::string& filename)
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