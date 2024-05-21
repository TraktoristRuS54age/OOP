#include "Vector.h"
const std::string END = "Vector is empty";
const std::string TEXT = "Vector values: ";

std::vector<float> VectorPrint(const std::vector<float>& ArrayNumbers, std::ofstream output)
{
    std::ofstream output;
    output.open("output.txt", std::ios::out);
    if (ArrayNumbers.size() == 0) {
        output << END;
        output.close();
        return ArrayNumbers;
    }
    output << TEXT;
    for (int i = 0; i < ArrayNumbers.size(); i++) {
        output << " " << ArrayNumbers[i];
    }
    output.close();
    return ArrayNumbers;
}