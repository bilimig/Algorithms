#include "Sort.h"

void quickSort(vector<MovieData>& arr, int left, int right) {
	int i = left, j = right;
	int pivot = arr[(left + right) / 2].averageRating;

	// Partition
	while (i <= j) {
		while (arr[i].averageRating < pivot) i++;
		while (arr[j].averageRating > pivot) j--;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	// Recursion
	if (left < j) quickSort(arr, left, j);
	if (i < right) quickSort(arr, i, right);
}

void merge(vector<MovieData>& arr, int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	// Tworzymy tablice tymczasowe
	vector<int> L(n1), R(n2);

	// Kopiujemy dane do tablic tymczasowych
	for (i = 0; i < n1; i++) {
		L[i] = arr[left + i].averageRating;
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[mid + 1 + j].averageRating;
	}

	// £¹czymy tablice tymczasowe z powrotem do tablicy pierwotnej
	i = 0; j = 0; k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k].averageRating = L[i];
			i++;
		}
		else {
			arr[k].averageRating = R[j];
			j++;
		}
		k++;
	}

	// Kopiujemy pozosta³e elementy L[], jeœli istniej¹
	while (i < n1) {
		arr[k].averageRating = L[i];
		i++;
		k++;
	}

	// Kopiujemy pozosta³e elementy R[], jeœli istniej¹
	while (j < n2) {
		arr[k].averageRating = R[j];
		j++;
		k++;
	}
}

void mergeSort(vector<MovieData>& arr, int left, int right) {
	if (left >= right) return;

	int mid = left + (right - left) / 2;

	// Dzielimy tablice na dwie czêœci
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);

	// £¹czymy posortowane czêœci
	merge(arr, left, mid, right);
}




void bucketSort(vector<MovieData>& moviesVec)
{
	int min = moviesVec.at(0).averageRating;
	int max = moviesVec.at(0).averageRating;
	int n = moviesVec.size();

	for (int i = 1; i < n; i++)
	{
		if (moviesVec.at(i).averageRating > max)
		{
			max = moviesVec.at(i).averageRating;
		}
		if (moviesVec.at(i).averageRating < min)
		{
			min = moviesVec.at(i).averageRating;
		}
	}
	int length = max - min + 1;
	vector<MovieData>* bucket = new vector<MovieData>[length];
	for (int i = 0; i < length; i++)
	{
		bucket[i] = vector<MovieData>();
	}
	for (int i = 0; i < n; i++)
	{
		bucket[moviesVec.at(i).averageRating - min].push_back(moviesVec.at(i));
	}
	int a = 0;
	for (int i = 0; i < length; i++)
	{
		int tempSize = bucket[i].size();
		if (tempSize > 0)
		{
			for (int j = 0; j < tempSize; j++)
			{
				moviesVec.at(a) = bucket[i][j];
				a++;
			}
		}
	}
}