#include <iostream>
#include "ranging.h"

int main() {
	//testing
	map <string, vector <int>> Members = {
	{"���1",{5,5,0}},
	{"���2",{5,10,0}},
	{"���3",{1,10,10}}
	};

	vector<string> surnames = getSurnames(Members);
	
	map <string, vector <int>> res = getSum(Members, surnames);
	cout << "End";
}