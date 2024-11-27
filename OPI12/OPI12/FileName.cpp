#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

// ������� ��� ��������� ����� ������ ������
void drawBorderWithText(int width, int height, const vector<string>& lines) {
    int textStartRow = (height - lines.size()) / 2;  // ��������� ������ ��� ������
    int textStartCol = (width - 2) / 2;             // ������������� ������ �� �����������

    // ������� �������
    for (int i = 0; i < width; i++) cout << "*";
    cout << endl;

    // ������ ������ � �������� ���������
    for (int i = 0; i < textStartRow; i++) {
        cout << "*";
        for (int j = 0; j < width - 2; j++) cout << " ";
        cout << "*" << endl;
    }

    // ����� ������
    for (const auto& line : lines) {
        cout << "*";
        int paddingLeft = (width - 2 - line.size()) / 2;  // ����� ������
        int paddingRight = width - 2 - line.size() - paddingLeft;

        for (int j = 0; j < paddingLeft; j++) cout << " ";
        cout << line;
        for (int j = 0; j < paddingRight; j++) cout << " ";
        cout << "*" << endl;
    }

    // ������ ������ ����� ������
    for (int i = 0; i < height - textStartRow - lines.size() - 1; i++) {
        cout << "*";
        for (int j = 0; j < width - 2; j++) cout << " ";
        cout << "*" << endl;
    }

    // ������ �������
    for (int i = 0; i < width; i++) cout << "*";
    cout << endl;
}

// �������������� ��������
void welcomeAnimation() {
    vector<string> lines = {
        "---------------------------",
        "|    ����� ����������!     |",
        "---------------------------"
    };
    drawBorderWithText(50, 10, lines);

    this_thread::sleep_for(chrono::milliseconds(500));
    for (int i = 0; i < 3; i++) {
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << endl << "�������� ���������!" << endl;
    system("cls");
}


// ������� ����
void mainMenu() {
    vector<string> menu = {
         "====== ������� ���� =======",
        "1. ������ ������ �������",
        "2. ��������� ������ �� �����",
        "3. ����� �� ���������",
        "�������� ��������: "
    };
    drawBorderWithText(50, 12, menu);
   
}

// ��������� ����� ������ �������
void manualInput() {
    string data;
    vector<string> prompt = { "������� ������ �������:" };
    drawBorderWithText(50, 10, prompt);
    cin.ignore();
    getline(cin, data);
    cout << "�� �����: " << data << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    for (int i = 0; i < 3; i++) {
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << endl << "�������� ���������!" << endl;
    system("cls");
}

// ������ ������ �� �����
void fileParser() {
    vector<string> prompt = { "������� ��� �����:" };
    drawBorderWithText(50, 10, prompt);

    string filename;
    cin >> filename;

    ifstream file(filename);
    if (file.is_open()) {
        vector<string> fileLines;
        string line;
        while (getline(file, line)) {
            fileLines.push_back(line);
        }
        file.close();
        drawBorderWithText(50, fileLines.size() + 4, fileLines);
        this_thread::sleep_for(chrono::milliseconds(500));
        for (int i = 0; i < 3; i++) {
            cout << ".";
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        cout << endl << "�������� ���������!" << endl;
        system("cls");
    }
    else {
        vector<string> error = { "������: ���� �� ������!" };
        drawBorderWithText(50, 10, error);
        this_thread::sleep_for(chrono::milliseconds(500));
        for (int i = 0; i < 3; i++) {
            cout << ".";
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        cout << endl << "�������� ���������!" << endl;
        system("cls");
    }
}

// ������� ��� ��������� ��������� ����
void setConsoleTitle(const string& title) {
    setlocale(LC_CTYPE, "Russian");
    wstring wideTitle(title.begin(), title.end());
    SetConsoleTitleW(wideTitle.c_str());
}

// ������� ��� ��������� ������� �������
void setConsoleSize(int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT rect = { 0, 0, width - 1, height - 1 };
    COORD coord = { width, height };
    SetConsoleScreenBufferSize(hConsole, coord);
    SetConsoleWindowInfo(hConsole, TRUE, &rect);
}

int main() {
    setConsoleSize(70 , 50);
    setlocale(LC_CTYPE, "Russian");
    setConsoleTitle("Project C++");
    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
  

    welcomeAnimation();  // �������� �����������

    int choice;
    while (true) {
        mainMenu();  // ������� ����
        cin >> choice;

        if (choice == 1) {
            manualInput();  // ���� ������ �������
        }
        else if (choice == 2) {
            fileParser();  // ������ ������ �� �����
        }
        else if (choice == 3) {
            cout << "����� �� ���������";
            this_thread::sleep_for(chrono::milliseconds(500));
            for (int i = 0; i < 3; i++) {
                cout << ".";
                this_thread::sleep_for(chrono::milliseconds(500));
            }
            cout << endl;
            break;  // ����� �� ���������
        }
        else {
            vector<string> error = { "������������ �����. ���������� �����!" };
            drawBorderWithText(50, 10, error);  // ������ ��� ������
        }
    }
    std::cin.get();
    return 0;
}
