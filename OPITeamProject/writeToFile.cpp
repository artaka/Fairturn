#include "input.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void writeToFile(vector<pair<string, vector<int>>> rangeDataMembers) {
	ofstream out;
	string path;
	cout << "Enter the name of the file to which the data will be written (default 'output.csv', enter 'd' for the default value): "; cin >> path;
	if (path == "d") {
		path = "output.csv";
	}
	out.open(path);
	if (!out.is_open()) {
		cout << "Error opening file!" << endl;
	}
	else {
		out << "Фамилия,Сдано,Сдается,Был ли,Сумма" << endl;
		for (const auto& pair : rangeDataMembers) {
			out << pair.first;
			for (int i = 0;i != 4;++i) {
				if (i == 2) {
					if (pair.second[i] == 10) {
						out << ",Да";
					}
					else {
						out << ",Нет";
					}
				}
				else {
					out << "," <<pair.second[i];
				}
			}
			out << endl;
		}
	}
	out.close();
}