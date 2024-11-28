#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;


// Function to draw a frame around text
void drawBorderWithText(int width, int height, const vector<string>& lines) {
    int textStartRow = (height - lines.size()) / 2;// Start line for text
    int textStartCol = (width - 2) / 2;             // Center text horizontally

    // Upper limit
    for (int i = 0; i < width; i++) cout << "*";
    cout << endl;

    // Empty lines with side borders
    for (int i = 0; i < textStartRow; i++) {
        cout << "*";
        for (int j = 0; j < width - 2; j++) cout << " ";
        cout << "*" << endl;
    }

    // Output text
    for (const auto& line : lines) {
        cout << "*";
        int paddingLeft = (width - 2 - line.size()) / 2;// Left indent
        int paddingRight = width - 2 - line.size() - paddingLeft;

        for (int j = 0; j < paddingLeft; j++) cout << " ";
        cout << line;
        for (int j = 0; j < paddingRight; j++) cout << " ";
        cout << "*" << endl;
    }

    // Empty lines after text
    for (int i = 0; i < height - textStartRow - lines.size() - 1; i++) {
        cout << "*";
        for (int j = 0; j < width - 2; j++) cout << " ";
        cout << "*" << endl;
    }


    // Lower bound
    for (int i = 0; i < width; i++) cout << "*";
    cout << endl;
}

// Welcome animation
void welcomeAnimation() {
    vector<string> lines = {
        "---------------------------",
        "|    Добро пожаловать!     |",
        "---------------------------"
    };
    drawBorderWithText(50, 10, lines);

    this_thread::sleep_for(chrono::milliseconds(500));
    for (int i = 0; i < 3; i++) {
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << endl << "Загрузка завершена!" << endl;
    system("cls");
}



// Main menu
void mainMenu() {
    vector<string> menu = {
         "====== Главное меню =======",
        "1. Ввести данные вручную",
        "2. Загрузить данные из файла",
        "3. Выйти из программы",
        "Выберите действие: "
    };
    drawBorderWithText(50, 12, menu);
   
}


// Handle manual input
void manualInput() {
    string data;
    vector<string> prompt = { "Введите данные вручную:" };
    drawBorderWithText(50, 10, prompt);
    cin.ignore();
    getline(cin, data);
    cout << "Вы ввели: " << data << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    for (int i = 0; i < 3; i++) {
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << endl << "Загрузка завершена!" << endl;
    system("cls");
}


// Parser data from file
void fileParser() {
    vector<string> prompt = { "Введите имя файла:" };
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
        cout << endl << "Загрузка завершена!" << endl;
        system("cls");
    }
    else {
        vector<string> error = { "Ошибка: файл не найден!" };
        drawBorderWithText(50, 10, error);
        this_thread::sleep_for(chrono::milliseconds(500));
        for (int i = 0; i < 3; i++) {
            cout << ".";
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        cout << endl << "Загрузка завершена!" << endl;
        system("cls");
    }
}

// Function to change the window title
void setConsoleTitle(const string& title) {
    setlocale(LC_CTYPE, "Russian");
    wstring wideTitle(title.begin(), title.end());
    SetConsoleTitleW(wideTitle.c_str());
}

// Function to set the console size
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
  

    welcomeAnimation(); // Welcome animation

    int choice;
    while (true) {
        mainMenu();  // Main menu
        cin >> choice;

        if (choice == 1) {
            manualInput();  // Enter data manually
        }
        else if (choice == 2) {
            fileParser();  // Parser data from file
        }
        else if (choice == 3) {
            cout << "Выход из программы";
            this_thread::sleep_for(chrono::milliseconds(500));
            for (int i = 0; i < 3; i++) {
                cout << ".";
                this_thread::sleep_for(chrono::milliseconds(500));
            }
            cout << endl;
            break;  // Exit the program
        }
        else {
            vector<string> error = { "Некорректный выбор. Попробуйте снова!" };
            drawBorderWithText(50, 10, error);  // Error during selection
        }
    }
    std::cin.get();
    return 0;
}
