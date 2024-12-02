#include "logo.h"
// Function for text animation
void startWelcomeAnimation() {
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
    Sleep(600);  // Pause before clearing the screen
    // Clear the screen with a fade-out effect
    for (int i = 0; i < 5; ++i) {
        system("cls");  // Clear the console
        Sleep(30);
    }
    system("cls");
}