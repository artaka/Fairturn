#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "input.h"
#include <stdio.h>
#include <Windows.h>

using namespace std;
map <string, vector<int>> dataEntry() {
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	map <string, vector<int>> membersListWithNumbers;
	int num, index;
	string sym = " ";
	cout << "Enter the number of participants: "; cin >> num;
	cout << "Enter the details of each participant one by one in the following format: <Last name> <number of labs taken> <number of the lab you are taking> <whether you were eligible to take the test at the previous lesson(yes - 10, no - 0)> AND \";\" IN THE END!\n";
	for (int i = 0; i < num; i++) {
		vector<int> numbers(3);
		string str, surname;
		cout << i + 1 << ". "; getline(cin, str, ';');
		index = str.find_first_of(sym);
		surname = str.substr(1, index - 1);
		str.erase(0, (index + 1));
		for (int i = 0; i < 3; i++) {
			index = str.find_first_of(sym);
			numbers[i] = stoi(str.substr(0, index));
			str.erase(0, (index + 1));
		}
		membersListWithNumbers[surname] = numbers;
	}
	system("cls");
	return membersListWithNumbers;
}