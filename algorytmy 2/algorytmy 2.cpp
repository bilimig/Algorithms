#include <iostream>
#include <chrono>
#include "Sort.h"
#include "ReadFromFile.h"
#include "MedianAverage.h" 

int main()
{
	vector<MovieData> movieData = get_csv_data("C:\\Users\\Kamil\\Downloads\\projekt2_dane.csv", 500000);
	int n = movieData.size();
	auto start = chrono::steady_clock::now();
	//mergeSort(movieData, 0, n-1);
	quickSort(movieData, 0, n-1);
	//bucketSort(movieData);
	auto end = chrono::steady_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
	/*for (int i = 0; i < n-1; i+=1000) {
		cout <<movieData[i].filmName << " " << movieData[i].averageRating <<"\n";
		}*/
	cout << "Czas wykonania: " << duration << " mikrosekund." << endl;
	cout << "srednia : " << calculateMean(movieData) << endl;
	cout << "mediana : " << median(movieData) << endl;


	return 0;

}

