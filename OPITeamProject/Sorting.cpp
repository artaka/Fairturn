#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Реализация функции для сортировки и вывода данных
void printSortedData(const map<string, vector<int>>& sortedMembers) {
    setlocale(LC_CTYPE, "Russian");
    // Вектор для хранения данных с сортировкой по фамилии
    vector<pair<string, vector<int>>> sortedVector(sortedMembers.begin(), sortedMembers.end());

    // Сортировка по фамилии
    sort(sortedVector.begin(), sortedVector.end(), [](const pair<string, vector<int>>& a, const pair<string, vector<int>>& b) {
        return a.first < b.first;  // Сортировка по фамилии (ключу)
        });

    // Номер строки для вывода
    int lineNumber = 1;

    // Выводим отсортированные данные с номером строки
    for (const auto& entry : sortedVector) {
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
