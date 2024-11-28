<<<<<<< HEAD
﻿#include <iostream>
=======
#include <iostream>
#include <map>
>>>>>>> 9bf3cea53a74633d26539c459c7f79f154a5d5e5
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Функция для сортировки и вывода данных
void printSortedData(vector<pair<string, vector<int>>>& sortedMembers) {
    setlocale(LC_CTYPE, "Russian");
<<<<<<< HEAD

    // Сортируем по фамилии (по первому элементу пары)
    sort(sortedMembers.begin(), sortedMembers.end(), 
        [](const pair<string, vector<int>>& a, const pair<string, vector<int>>& b) {
            return a.first < b.first;  // Сортируем по имени (фамилии)
        });
=======
>>>>>>> 9bf3cea53a74633d26539c459c7f79f154a5d5e5

    // Номер строки для вывода
    int lineNumber = 1;

    // Выводим отсортированные данные с номером строки
    for (const auto& entry : sortedMembers) {
        const string& surname = entry.first;
        const vector<int>& data = entry.second;

        int labsPassed = data[0];       // Количество сданных лабораторных
        int labsToDo = data[1];         // Количество лабораторных, которые предстоит сдать
        int attendedValue = data[2];    // 0 - не был, 10 - был
        int totalScore = data[3];       // Общий балл

        // Определяем, был ли на занятии
        string attended = (attendedValue == 10) ? "Да" : "Нет";

        // Выводим информацию с номером строки
        cout << lineNumber++ << ". " << surname << " "
            << labsPassed << " "
            << labsToDo << " "
            << attended << " "
            << totalScore << endl;
    }
}
