#pragma once
#include <string>
#include <vector>
using namespace std;

struct MovieData {
	MovieData(string filmName, int averageRating)
	{
		this->filmName = filmName;
		this->averageRating = averageRating;
	}

	string filmName;
	int averageRating;

};