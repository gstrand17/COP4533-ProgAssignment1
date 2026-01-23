#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include "matcher.cpp"
using namespace std;


int main() {
    ifstream inFile ("../example.txt");
    if (!inFile.is_open()){
        cout << "Error opening file" << endl;
        return -1;
    }
    string str_n; // parse n
    getline(inFile, str_n);
    cout << "string n is " << str_n << endl;
    int n = stoi(str_n); //convert to int
    cout << "int n = " << n << endl;
    map<int, vector<int>> hospitals;
    map<int, vector<int>> students;

    string str;
    for (int i = 1; i <= n; i++) {
        vector<int> temp;
        getline(inFile, str);
        stringstream ss(str);
        for (int j = 0; j < n; j++) {
            getline(ss,str, ' ');
            temp.push_back(stoi(str));
        }
        hospitals[i] = temp;
    }
    for (int i = 1; i <= n; i++) {
        vector<int> temp;
        getline(inFile, str);
        stringstream ss(str);
        for (int j = 0; j < n; j++) {
            getline(ss,str, ' ');
            temp.push_back(stoi(str));
        }
        students[i] = temp;
    }
    for (auto n: hospitals) {
        cout << "Hosptial: "<< n.first << " list: "; ;
        for (int i = 0; i < n.second.size(); i++) {
            cout << n.second[i] << " ";
        }
        cout << endl;
    }
    for (auto n: students) {
        cout << "Student: "<< n.first << " list: "; ;
        for (int i = 0; i < n.second.size(); i++) {
            cout << n.second[i] << " ";
        }
        cout << endl;
    }

    matcher(hospitals, students, n);
    return 0;
}
