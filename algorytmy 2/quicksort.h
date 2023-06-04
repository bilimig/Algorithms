#include <iostream>
#include <vector>
#pragma once
    using namespace std;

class quicksort
{


    void quickSort(vector<int>& arr, int left, int right) {
        int i = left, j = right;
        int pivot = arr[(left + right) / 2];

        // Partition
        while (i <= j) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
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
};

