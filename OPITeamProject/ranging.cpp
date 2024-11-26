#include <vector>
#include <string>
#include <map>
using namespace std;

vector<string> getSurnames(map <string, vector <int>> members) {
	vector<string> surnames; // vector of surnames
	for (auto& item : members)
	{
		surnames.push_back(item.first);
	}
	return surnames;
}

map <string, vector <int>> getSum(map <string, vector <int>> members, vector<string> surnames) {

	for (int i = 0;i != members.size(); ++i) {
		int sum = 0;
		for (int j = 0;j != 3;++j) {
			sum += members[surnames[i]][j];
		}
		members[surnames[i]].push_back(sum); // Getting sum of every points and add to the back of vector
	}
	return members;
}

/*
Typical Output:
map <string, vector <int>> sortedMembers = {
	{"Чел1",{5,5,0,10}},
	{"Чел2",{5,10,0,15}},
	{"Чел3",{1,10,10,21}}
};
*/