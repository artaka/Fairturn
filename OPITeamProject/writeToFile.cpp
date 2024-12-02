#include "input.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void writeToFile(vector<pair<string, vector<int>>> rangeDataMembers) {
	ofstream out;
	string path;
	cout << "Enter the file name where the data will be written in the format 'name.csv' (Press n to select the default file 'output.csv'): "; cin >> path;
	if (path == "n") {
		path = "output.csv";
	}
	out.open(path);
	if (!out.is_open()) {
		cout << "Error opening file!" << endl;
	}
	else {
		for (const auto& pair : rangeDataMembers) {
			out << pair.first;
			for (int num : pair.second) {
				out << ";" << num;
			}
			out << endl;
		}
	}
	out.close();
}