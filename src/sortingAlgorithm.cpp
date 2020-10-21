#include "../sorting/sortingAlgorithm.hpp"

void bubbleSort(int lista[], int tam)
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
}

void swap(int &a, int &b)
{
	int aux = a;
	a = b;
	b = aux;
}

int partition(int lista[], int left, int right)
{
	int pivot = lista[right];
	int i = (left - 1);

	for (int j = left; j <= right - 1; j++)
	{
		if (lista[j] <= pivot)
		{
			i++;
			swap(lista[i], lista[j]);
		}
	}
	swap(lista[i + 1], lista[right]);
	return (i + 1);
}

void quickSort(int lista[], int left, int right)
{
	if (left < right)
	{
		int pi = partition(lista, left, right);
		quickSort(lista, left, pi - 1);
		quickSort(lista, pi + 1, right);
	}
}
