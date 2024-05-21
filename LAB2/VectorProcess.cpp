#include "Vector.h"
const std::string ZERO = "smaller element = 0, cannot be divided by 0";

std::vector<float> VectorProcess(std::vector<float>& ArrayNumbers)
{
    if(ArrayNumbers.size() == 0) return ArrayNumbers;

    float maxElement = *std::max_element(begin(ArrayNumbers), end(ArrayNumbers)), resultArray = 0;
    if (maxElement == 0) {
        std::cout << ZERO << std::endl;
        return ArrayNumbers;
    }
    maxElement = maxElement / 2;

    for (int i = 0; i < ArrayNumbers.size(); i++) {
        resultArray = ArrayNumbers[i] / maxElement;
        resultArray = floor(resultArray * 1000) / 1000;
        ArrayNumbers[i] = resultArray;
    }

    return ArrayNumbers;
}
//std::dbl_epsilon вместо floor поменять и использвать для тестов --
//стандартный алгоритм трансформ --
//добавить деление на 0 ++

//stringstream почитать про него и тесты переделать под него (проверка VectorPrint)