// вариант 3
// Каждый элемент массива должен быть умножен на минимальный элемент исходного массива Подсказка: используйте алгоритм std::min_element
#include "Vector.h"

int main()
{
	std::vector<float> ArrayNumbers;
	VectorProcess(ArrayNumbers);
	std::sort(ArrayNumbers.begin(), ArrayNumbers.end(), SortVector);
	VectorPrint(ArrayNumbers);
	return 0;
}