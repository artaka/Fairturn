#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

vector<string> getSurnames(map<string, vector<int>> members) {
    vector<string> surnames;
    for (auto& item : members) {
        surnames.push_back(item.first);
    }
    return surnames;
}

map<string, vector<int>> getSum(map<string, vector<int>> members, vector<string> surnames) {
    for (int i = 0; i < members.size(); ++i) {
        int prev = members[surnames[i]][0];     
        int submitting = members[surnames[i]][1];
        int attended = members[surnames[i]][2];  
        int current = members[surnames[i]][3];   

        int sum = prev + submitting + attended;

        if (submitting == current) {
            sum -= 10;
        }

        string sname = surnames[i];
        if (sname == "Макаревич" || sname == "Мышковец") {
            sum -= 2;
        }

        // итог
        if (members[surnames[i]].size() == 4) {
            members[surnames[i]].push_back(sum);
        }
        else {
            members[surnames[i]][4] = sum;
        }
    }
    return members;
}

vector<pair<string, vector<int>>> ranging(map<string, vector<int>> membersList) {
    vector<string> surnames = getSurnames(membersList);
    map<string, vector<int>> members = getSum(membersList, surnames);

    vector<pair<string, vector<int>>> sortedMembers;

    for (auto& s : surnames) {
        sortedMembers.push_back(make_pair(s, members[s]));
    }

    sort(sortedMembers.begin(), sortedMembers.end(),
        [](const pair<string, vector<int>>& a, const pair<string, vector<int>>& b) {
            return a.second[4] < b.second[4]; // меньше = выше
        });

    return sortedMembers;
}
