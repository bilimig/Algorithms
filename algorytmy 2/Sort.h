#pragma once
#include "Moviedata.h"

void quickSort(vector<MovieData>& arr, int left, int right);
void merge(vector<MovieData>& arr, int left, int mid, int right);
void mergeSort(vector<MovieData>& arr, int left, int right);
void bucketSort(vector<MovieData>& moviesVec);