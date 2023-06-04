#include "ReadFromFile.h"

vector<MovieData> get_csv_data(string fileName, int size) {
	vector<MovieData> data;
	fstream file(fileName);
	if (file.is_open()) {
		string line;

		for (int i = 0; i < size; i++) {
			getline(file, line);
			if (i != 0) {
				//Parse the line expect header line
				//Get helpful indexes
				size_t index = line.find(',');
				size_t indexLast = line.find_last_of(',');

				//Get substrings with movie name and rating
				string movieName = line.substr(index + 1, indexLast - index - 1);
				string rating_string = line.substr(indexLast + 1);

				//Create object only if rating exists
				if (rating_string != "") {
					int rating = stoi(rating_string);
					MovieData mov(movieName, rating);
					//mov.print_data();
					data.push_back(mov);
				}
			}
		}
	}
	return data;

}
