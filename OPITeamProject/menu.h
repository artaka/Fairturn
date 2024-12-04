#pragma once
#include <vector>
#include <string>
using namespace std;
void drawBorderWithText(int width, int height, const vector<string>& lines);
void welcomeAnimation();
void mainMenu();
void setConsoleTitle(const string& title);
void setConsoleSize(int width, int height);