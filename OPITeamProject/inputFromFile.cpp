#include <iostream>
#include "inputFromFile.h"
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <Windows.h>
using namespace std;

map <string, vector<int>> inputFromFile() {
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int index;
	string sym = ";", surname;
	vector<int> data(3);
	map <string, vector<int>> memberList;
	string path = "output.csv";
	ifstream in;
	in.open(path);
	if (!in.is_open()) {
		cout << "������ �������� �����!" << endl;
	}
	else {
		cout << "���� ������!" << endl;
		string str;
		while (getline(in, str)) {
			if (str.empty()) continue;
			index = str.find_first_of(sym);
			surname = str.substr(0, index);
			str.erase(0, (index + 1));
			for (int i = 0; i < 3; i++) {
				index = str.find_first_of(sym);
				data[i] = stoi(str.substr(0, index));
				str.erase(0, (index + 1));
			}
			memberList[surname] = data;
		}
	}
	in.close();
	return memberList;
}