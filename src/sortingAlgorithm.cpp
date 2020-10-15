#include "../sorting/sortingAlgorithm.hpp"

void bubbleSort(std::vector<int> *lista)
{
	int k = 1;
	int aux = 0;
	size_t tam = lista->size();
	for (size_t i = 0; i < tam; i++)
	{
		for (size_t j = k; j < tam; j++)
		{
			if (lista->at(i) > lista->at(j))
			{
				aux = lista->at(i);
				// std::cout << " index"
				// 					<< "(" << i << ") "
				// 					<< "(" << j << ")"
				// 					<< "\n";
				lista->at(i) = lista->at(j);
				lista->at(j) = aux;
				// for (size_t l = 0; l < tam; l++)
				// {
				// 	std::cout << lista->at(l) << " ";
				// }
				// std::cout << "\n";
			}
		}
		k++;
	}
}

void quickSort(std::vector<int> *lista)
{
	int piv = (lista->size()) / 2;
	int left = 0;
	int right = (lista->size() - 1);
	int aux = 0;

	std::cout << lista->at(piv) << "\n";

	while (left <= right)
	{
		while (lista->at(left) <= lista->at(piv))
		{
			std::cout << "entrou aqui " << left << " "
								<< "\n ";
			left++;
		};
		while (lista->at(right) >= lista->at(piv))
		{
			right++;
		}

		if (lista->at(left) > lista->at(right))
		{
			aux = lista->at(left);
			lista->at(left) = lista->at(right);
			lista->at(right) = aux;
			left++;
			right--;
		};
	}
	for (size_t i = 0; i < (lista->size() - 1); i++)
	{
		std::cout << lista->at(i) << " ";
	}
	std::cout << "\n";
}
