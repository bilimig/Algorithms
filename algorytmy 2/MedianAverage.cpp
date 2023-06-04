#include "MedianAverage.h" 

double calculateMean(vector<MovieData>& data) {
    double sum = 0.0;
    for (const auto& movie : data) {
        sum += movie.averageRating;
    }
    return sum / data.size();
}

double median(const vector<MovieData>& data) {
    const int n = data.size();
    if (n % 2 == 1) {  // nieparzysta liczba elementów
        return data[(n / 2)].averageRating;
    }
    else {  // parzysta liczba elementów
        const int idx1 = n / 2 - 1;
        const int idx2 = n / 2;
        return (data[idx1].averageRating + data[idx2].averageRating) / 2.0;
    }
}