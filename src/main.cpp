#include <iostream>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <vector>
#include "../sorting/sortingAlgorithm.hpp"
#include <random>

using namespace std;

int main()
{

	ofstream quickF, bubbleF;
	quickF.open("data/quick.txt");
	bubbleF.open("data/bubble.txt");

	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(1, 100);

	int quickValues[100], bubbleValues[100];

	for (int i{50}; i < 10000; i += 50)
	{
		int listaBubble[i];
		int listaQuick[i];

		long double quickSortSum{0}, bubbleSortSum{0}, quickSortAverage, bubbleSortAverege;

		for (int k{0}; k < 100; k++)
		{
			for (int j{0}; j < i; j++)
			{
				listaBubble[j] = uniform_dist(e1);
				listaQuick[j] = uniform_dist(e1);
			}

			auto startChrono = chrono::steady_clock::now();

			bubbleSort(listaBubble, (sizeof(listaBubble) / sizeof(listaBubble[i]) - 1));

			auto endChrono = chrono::steady_clock::now();
			auto timeDifference = endChrono - startChrono;

			bubbleValues[k] = chrono::duration<long double, std::milli>(timeDifference).count();

			startChrono = chrono::steady_clock::now();

			quickSort(listaQuick, 0, (sizeof(listaQuick) / sizeof(listaQuick[0])));

			endChrono = chrono::steady_clock::now();
			timeDifference = endChrono - startChrono;

			quickValues[k] = chrono::duration<long double, std::milli>(timeDifference).count();
		}
		for (int z{0}; z < 100; z++)
		{
			quickSortSum += quickValues[z];
			bubbleSortSum += bubbleValues[z];
		}
		bubbleSortAverege = bubbleSortSum / 100;
		quickSortAverage = quickSortSum / 100;

		quickF << quickSortAverage << " "
					 << endl;
		bubbleF << bubbleSortAverege << " "
						<< endl;
	}

	return 0;
};
