#include <iostream>
#include "ranging.h"

int main() {
	//testing
	map <string, vector <int>> Members = {
	{"���",{5,5,0}},//1
	{"����",{5,10,10}},//3
	{"����",{1,10,10}}//2
	};

	vector<string> surnames = getSurnames(Members);
	
	map <string, vector <int>> res = getSum(Members, surnames);

	vector<pair<string, vector<int>>> out = ranging(res, surnames);
	cout << "End";
}