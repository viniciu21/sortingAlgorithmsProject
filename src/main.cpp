#include <iostream>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <vector>
#include "../sorting/sortingAlgorithm.hpp"

int main()
{
	std::vector<int> list{23, 123, 15, 678, 91, 0, 23, -1, 10};
	quickSort(&list);
	return 0;
};
