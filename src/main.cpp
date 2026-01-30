#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <chrono>
#include "matcher.cpp"
#include "checker.cpp"
#include "generator.cpp"
using namespace std;


int main() {
    vector<pair<int, float>> matcherTime;
    vector<pair<int,float>> checkerTime;
    vector<int> nArray{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    vector<string> fileList = generator(nArray);
    for (string file : fileList){
        ifstream inFile (file);
        if (!inFile.is_open()){
            cout << "Error opening file" << endl;
            return -1;
        }
        string str_n; // parse n
        getline(inFile, str_n);
        int n = stoi(str_n); //convert to int
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
        vector<pair<int,int>> matched;
        matched = matcher(hospitals, students, n, matcherTime);
        bool stable = verify(matched, hospitals, students, n, checkerTime);


    }
    ofstream matchFile ("../matchingTime.csv");
    cout << "Run times for matcher" << endl;
    for (auto time : matcherTime) {
        cout << "N= " << time.first << " Time = " << time.second << " seconds" << endl;
        matchFile << time.first << "," << time.second << endl;
    }
    matchFile.close();
    ofstream checkFile ("../checkTime.csv");
    cout << "Run times for checker" << endl;
    for (auto time: checkerTime) {
        cout << "N= " << time.first << " Time = " << time.second << " seconds" << endl;
        checkFile << time.first << "," << time.second << endl;
    }
    checkFile.close();
    return 0;
}
