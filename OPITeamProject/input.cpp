#define _CRT_SECURE_NO_WARNINGS
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
	int num, number1, number2, number3;
	char surname[15];
	map <string, vector<int>> membersListWithNumbers;

	cout << "Enter the number of participants:"; cin >> num;
	cout << "Enter the details of each participant one by one in the following format: <Last name> <number of labs taken> <number of the lab you are taking> <whether you were eligible to take the test at the previous lesson(yes - 10, no - 0)>.\n";
	for (int i = 0; i < num; i++) {
		vector<int> numbers(3);
		cout << i + 1 << ". "; scanf("%10s %d %d %d", surname, &number1, &number2, &number3);
		numbers[0] = number1;
		numbers[1] = number2;
		numbers[2] = number3;
		membersListWithNumbers[surname] = numbers;
	}
	return membersListWithNumbers;
}