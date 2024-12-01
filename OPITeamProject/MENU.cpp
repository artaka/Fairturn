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
    // Top border with animation
    for (int i = 0; i < width; i++) {
        cout << "*";
        this_thread::sleep_for(chrono::milliseconds(10));  // Delay
    }
    cout << endl;

    // Blank lines before text
    for (int i = 0; i < (height - lines.size()) / 2; i++) {
        cout << "*";
        for (int j = 0; j < width - 2; j++) cout << " ";
        cout << "*" << endl;
        this_thread::sleep_for(chrono::milliseconds(20));  // Delay
    }

    // Outputting text with animation
    for (const auto& line : lines) {
        cout << "*";
        int paddingLeft = (width - 2 - line.size()) / 2;
        int paddingRight = width - 2 - line.size() - paddingLeft;

        for (int j = 0; j < paddingLeft; j++) cout << " ";

        for (char c : line) {
            cout << c << flush;
            this_thread::sleep_for(chrono::milliseconds(20));  // Per-character delay
        }

        for (int j = 0; j < paddingRight; j++) cout << " ";
        cout << "*" << endl;
        this_thread::sleep_for(chrono::milliseconds(20));  //Delay between lines of text
    }

    // Blank lines after text
    for (int i = 0; i < (height - lines.size() - 1) / 2; i++) {
        cout << "*";
        for (int j = 0; j < width - 2; j++) cout << " ";
        cout << "*" << endl;
        this_thread::sleep_for(chrono::milliseconds(20));  // Delay
    }

    // Bottom border with animation
    for (int i = 0; i < width; i++) {
        cout << "*";
        this_thread::sleep_for(chrono::milliseconds(10));  // Delay
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
        " \\$$       \\$$$$$$$ \\$$ \\$$         \\$$$$   \\$$$$$$  \\$$       \\$$   \\$$"
    };
    // Loop through each line of text
    for (const string& line : lines) {
        // Print each character in the line with a small delay
        for (char c : line) {
            cout << c << flush;  // Immediately output the character to the console
            Sleep(0.99);            // Delay between characters (in milliseconds)
        }
        cout << endl;
        Sleep(250);  // Delay between lines
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
         "====== Main menu =======",
        "1. Enter data manually"   ,
        "2. Load data from file"   ,
        "3. Exit the program   "   ,


    };
    drawBorderWithText(50, 12, menu);

}


// Handle manual input
void manualInput() {
    string data;
    vector<string> prompt = { "Enter data manually:" };
    drawBorderWithText(50, 10, prompt);
    cin.ignore();
    getline(cin, data);
    cout << "You entered: " << data << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    for (int i = 0; i < 3; i++) {
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << endl << "Download complete!" << endl;
    system("cls");
}


// Parser data from file
void fileParser() {
    vector<string> prompt = { "Enter file id:" };
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
        cout << endl << "Download complete!" << endl;
        system("cls");
    }
    else {
        vector<string> error = { "Error: file not found" };
        drawBorderWithText(50, 10, error);
        this_thread::sleep_for(chrono::milliseconds(500));
        for (int i = 0; i < 3; i++) {
            cout << ".";
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        cout << endl << "Download complete!" << endl;
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
    setConsoleSize(70, 50);
    setlocale(LC_CTYPE, "Russian");
    setConsoleTitle("FAIRTURN");
    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);


    welcomeAnimation(); // Welcome animation

    int choice;
    while (true) {
        mainMenu();  // Main menu
        cout << "Select action: ";
        cin >> choice;
        system("cls");

        if (choice == 1) {
            manualInput();  // Enter data manually
        }
        else if (choice == 2) {
            fileParser();  // Parser data from file
        }
        else if (choice == 3) {


            string message = "Exit the program...";


            for (char c : message) {
                cout << c << flush;
                this_thread::sleep_for(chrono::milliseconds(100));  // Pause between characters
            }
            cout << endl;
            break;  // Exit the program
        }
        else {
            vector<string> error = { "Incorrect choice. Try again!" };
            drawBorderWithText(50, 10, error);  // Error during selection
            this_thread::sleep_for(chrono::milliseconds(500));
            for (int i = 0; i < 3; i++) {
                cout << ".";
                this_thread::sleep_for(chrono::milliseconds(500));
            }
            cout << endl << "Download complete!" << endl;
            system("cls");
        }
    }
    std::cin.get();
    return 0;
}
