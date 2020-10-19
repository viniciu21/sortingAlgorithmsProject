#include "../sorting/sortingAlgorithm.hpp"

int bubbleSort(int lista[], int tam)
{
	int k = 1;
	int aux = 0;
	for (int i = 0; i < tam; i++)
	{
		for (int j = k; j < tam; j++)
		{
			if (lista[i] > lista[j])
			{
				aux = lista[i];
				lista[i] = lista[j];
				lista[j] = aux;
			}
		}
		k++;
	}
	return 1;
}

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

int partition(int lista[], int low, int high)
{
	int pivot = lista[high]; // pivot
	int i = (low - 1);			 // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (lista[j] <= pivot)
		{
			i++; // increment index of smaller element
			swap(lista[i], lista[j]);
		}
	}
	swap(lista[i + 1], lista[high]);
	return (i + 1);
}

int quickSort(int lista[], int left, int right)
{
	if (left < right)
	{
		int pi = partition(lista, left, right);
		quickSort(lista, left, pi - 1);
		quickSort(lista, pi + 1, right);
	}
	return 1;
}
