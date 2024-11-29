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

	cout << "¬ведите количество участников: "; cin >> num;
	cout << "¬ведите поочередно данные каждого участника в виде: ‘амили€,кол-во сданных лаб,номер лабы которую сдаете,подходил ли сдавать на прошлом зан€ти.\n";
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