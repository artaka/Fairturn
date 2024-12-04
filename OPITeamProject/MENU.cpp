#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


// Function to draw a frame around text
void drawBorderWithText(int width, int height, const vector<string>& lines) {
    // Top border with animation
    for (int i = 0; i < width; i++) {
        cout << "*";
        Sleep(20);  // Delay
    }
    cout << endl;

    // Blank lines before text
    for (int i = 0; i < (height - lines.size()) / 2; i++) {
        cout << "*";
        for (int j = 0; j < width - 2; j++) cout << " ";
        cout << "*" << endl;
        Sleep(20);  // Delay
    }

    // Outputting text with animation
    for (const auto& line : lines) {
        cout << "*";
        int paddingLeft = (width - 2 - line.size()) / 2;
        int paddingRight = width - 2 - line.size() - paddingLeft;

        for (int j = 0; j < paddingLeft; j++) cout << " ";

        for (char c : line) {
            cout << c << flush;
            Sleep(20);  // Per-character delay
        }

        for (int j = 0; j < paddingRight; j++) cout << " ";
        cout << "*" << endl;
        Sleep(20);  //Delay between lines of text
    }

    // Blank lines after text
    for (int i = 0; i < (height - lines.size() - 1) / 2; i++) {
        cout << "*";
        for (int j = 0; j < width - 2; j++) cout << " ";
        cout << "*" << endl;
        Sleep(20);  // Delay
    }

    // Bottom border with animation
    for (int i = 0; i < width; i++) {
        cout << "*";
        Sleep(20);  // Delay
    }
    cout << endl;
}

// Welcome animation
void   welcomeAnimation() {
    // Array of strings to display as animated text
    string lines[] = {
        "  ______            __             __                                   ",
        " /      \\          |  \\           |  \\                                  ",
        "|  $$$$$$\\ ______   \\$$  ______  _| $$$_    __    __   ______   _______  ",
        "| $$_  \\$$|      \\ |  \\ /      \\|   $$ \\  |  \\  |  \\ /      \\ |       \\ ",
        "| $$ \\     \\$$$$$$\\| $$|  $$$$$$\\\\$$$$$$  | $$  | $$|  $$$$$$\\| $$$$$$$\\",
        "| $$$$    /      $$| $$| $$   \\$$ | $$ __ | $$  | $$| $$   \\$$| $$  | $$",
        "| $$     |  $$$$$$$| $$| $$       | $$|  \\| $$__/ $$| $$      | $$  | $$",
        "| $$      \\$$    $$| $$| $$        \\$$  $$ \\$$    $$| $$      | $$  | $$",
        " \\$$       \\$$$$$$$ \\$$ \\$$         \\$$$$   \\$$$$$$  \\$$       \\$$   \\$$",
    };
    // Loop through each line of text
    for (const string& line : lines) {
        // Print each character in the line with a small delay
        for (char c : line) {
            cout << c << flush;  // Immediately output the character to the console
            Sleep(0.99);            // Delay between characters (in milliseconds)
        }
        cout << endl;
        Sleep(500);  // Delay between lines
    }
    Sleep(800);  // Pause before clearing the screen
    // Clear the screen with a fade-out effect
    for (int i = 0; i < 5; ++i) {
        system("cls");  // Clear the console
        Sleep(50);
    }
    system("cls");
}



// Main menu
void mainMenu() {
    vector<string> menu = {
        "Fairnturn",
        "",
         "====== Main menu =======",
        "1. Enter data manually"   ,
        "2. Load data from Google Sheets"   ,
        "3. Exit the program   "   ,


    };
    drawBorderWithText(50, 12, menu);

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