#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <Windows.h>
using namespace std;

map<string, vector<int>> inputFromFile() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Russian");

    int index;
    string surname;
    wchar_t sym = L','; // CSV разделитель
    vector<int> data(4);
    map<string, vector<int>> memberList;
    string path;

    cout << "Enter CSV file name (default 'output.csv', enter 'd'): ";
    cin >> path;
    if (path == "d") {
        path = "output.csv";
    }

    ifstream in(path);
    if (!in.is_open()) {
        cout << "Error opening file!" << endl;
        return memberList;
    }

    int currentLab;
    cout << "Enter current lab number: ";
    cin >> currentLab;

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
                if (dat == "да" || dat == "Да" || dat == "yes" || dat == "Yes") {
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

        data[3] = currentLab;
        memberList[surname] = data;
    }
    in.close();

    cout << "File loaded successfully!" << endl;
    return memberList;
}
