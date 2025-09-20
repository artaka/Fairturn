#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "input.h"
#include <Windows.h>

using namespace std;

map<string, vector<int>> dataEntry() {
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);

    map<string, vector<int>> membersListWithNumbers;
    int num, index;
    string sym = " ";

    cout << "Enter the number of participants: ";
    cin >> num;

    int currentLab;
    cout << "Enter current lab number: ";
    cin >> currentLab;

    cout << "Enter details for each participant in format:\n";
    cout << "<LastName> <labsPassed> <submittingLab> <attended(yes-10 / no-0)> ;\n";

    cin.ignore(); // очистка буфера

    for (int i = 0; i < num; i++) {
        vector<int> numbers(4);
        string str, surname;
        cout << i + 1 << ". ";
        getline(cin, str, ';');
        index = str.find_first_of(sym);
        surname = str.substr(0, index);
        str.erase(0, (index + 1));
        for (int j = 0; j < 3; j++) {
            index = str.find_first_of(sym);
            numbers[j] = stoi(str.substr(0, index));
            str.erase(0, (index + 1));
        }
        numbers[3] = currentLab; // добавляем текущую лабу
        membersListWithNumbers[surname] = numbers;
    }
    system("cls");
    return membersListWithNumbers;
}
