#pragma once
#include <map>
#include <vector>
#include <string>
using namespace std;

vector<string> getSurnames(map <string, vector <int>> members);
map <string, vector <int>> getSum(map <string, vector <int>> members, vector<string> surnames);