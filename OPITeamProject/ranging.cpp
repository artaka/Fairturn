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

	for (int i = 0;i != members.size();++i) {

		int sum = 0;

		for (int j = 0;j != 3;++j) {
			sum += members[surnames[i]][j];
		}
		members[surnames[i]].push_back(sum); // Getting sum of every points and add to the back of vector
	}

	return members;
}

vector<pair<string, vector<int>>> ranging(map <string, vector <int>> membersList) {

	vector<string> surnames = getSurnames(membersList);
	map <string, vector <int>> members = getSum(membersList,surnames);
	pair<string, vector<int>> data;
	vector<pair<string, vector<int>>> sortedMembers; // vector for return sorted list with std::pair
	int size = surnames.size(); // variable for get common size of surname vector once per iteration

	while (size != 1) { // while in map have more then 1 pair

		int minIndex = 0;
		
		for (int j = 1;j != size;++j) { // get surname index with minimal sum

			if (members[surnames[j]][3] < members[surnames[minIndex]][3]) {
				minIndex = j;
			}
		}

		
		data = make_pair(surnames[minIndex], members[surnames[minIndex]]); // meke pair for push to vector
		sortedMembers.push_back(data);

		members.erase(surnames[minIndex]); // deleting common surname from surnames vector

		vector<string>::iterator it;
		it = find(surnames.begin(), surnames.end(), surnames[minIndex]);
		surnames.erase(it); // deleting common surname from members map

		size = surnames.size(); // updating size of vector
	}

	data = make_pair(surnames[0], members[surnames[0]]); // when in map only one pair we pushing his to vector
	sortedMembers.push_back(data);

	return sortedMembers;
}

/*
Typical Output:
vector<pair<string, vector<int>>> sortedMembers = {
	{"Аня",{5,5,0,10}},
	{"Ваня",{5,10,0,15}},
	{"Саня",{1,10,10,21}}
};
*/