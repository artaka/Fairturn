#include <iostream>
#include "input.h"
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <codecvt>
#include <Windows.h>
using namespace std;

map <string, vector<int>> inputFromFile() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, "Russian");
	cout.imbue(locale(""));

	int index;
	string surname;
	wchar_t sym = L',';
	vector<int> data(3);
	map <string, vector<int>> memberList;
	string path;
	cout << "Enter the file name where the data will be written in the format 'name.csv' (Press d to select the default file 'output.csv'): "; cin >> path;
	if (path == "d") {
		path = "output.csv";
	}
	ifstream in(path);

	if (!in.is_open()) {
		cout << "Error opening file!" << endl;
	}
	else {
		string str;
		while (getline(in, str)) {
			if (str.empty()) continue;
			
			index = str.find_first_of(sym);
			surname = str.substr(0, index);
			str.erase(0, (index + 1));
			for (int i = 0; i < 3; i++) {
				index = str.find_first_of(sym);
				if (i == 2) {
					string dat = str.substr(0, index);
					if (dat == "да") {
						data[i] = 10;
					}
					else {
						data[i] = 0;
					}
				}
				else {
					data[i] = stoi(str.substr(0, index));
				}
				
				str.erase(0, (index + 1));
			}
			memberList[surname] = data;
		}
		cout << "File opened, writing to map was successful!" << endl;
	}
	in.close();
	return memberList;
}