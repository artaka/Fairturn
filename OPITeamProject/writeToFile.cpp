#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void writeToFile(vector<pair<string, vector<int>>> rangeDataMembers) {
    ofstream out("output.txt");
    ofstream csv("output.csv");

    out << "Surname  Prev  Submitting  Attended  Current  Score\n";
    csv << "Surname,Prev,Submitting,Attended,Current,Score\n";

    for (auto& entry : rangeDataMembers) {
        string surname = entry.first;
        vector<int> data = entry.second;

        string attended = (data[2] == 10 ? "Yes" : "No");

        out << surname << " "
            << data[0] << " "
            << data[1] << " "
            << attended << " "
            << data[3] << " "
            << data[4] << "\n";

        csv << surname << ","
            << data[0] << ","
            << data[1] << ","
            << attended << ","
            << data[3] << ","
            << data[4] << "\n";
    }

    out.close();
    csv.close();
    cout << "Data written to output.txt and output.csv" << endl;
}
