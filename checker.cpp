#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono>
using namespace std;

int findPref(int target, int match, map<int, vector<int>> prefMap, int n){
    // target could be a student or hospital number
    // match could either be the hospital paired to the target student, or the student paired to the target hospital
    // if target is a student, prefMap is students map. if target is hospitals, prefMap is hospitals map
    for (int i=0; i<n; i++){
        if(prefMap[target][i] == match){ //locates exactly the index that the match is at in the preference list
            return i+1; // returns preference i.e. 1st, 2nd, 3rd, 4th, 5th (excludes 0th)
        }
    }
    return -1;
}

bool HappyH (int currHosp, int choice, map<int,vector<int>> hospitals, map<int,vector<int>> students, vector<pair<int,int>> matching, int n) {
    for (int option = choice - 1; option > 0; option--) {
        int nChoice = hospitals[currHosp][option -1 ];
        int nPartner;
        for (auto &matches : matching) {
            if (matches.second == nChoice) {
                nPartner = matches.first;
            }
        }
        int currMatchIndex = findPref(nChoice, nPartner, students, n);
        int nMatchCurrHIndex = findPref(nChoice, currHosp, students, n);
        if (currMatchIndex > nMatchCurrHIndex) {
            return false;
        }
    }
    return true;
}

bool HappyS (int currStud, int choice, map<int,vector<int>> hospitals, map<int,vector<int>> students, vector<pair<int,int>> matching, int n) {
    for (int option = choice - 1; option > 0; option--) {
        int nChoice = students[currStud][option-1];
        int nPartner; // vector indexed at zero
        for (auto &matches : matching) {
            if (matches.first == nChoice) {
                nPartner= matches.second;
            }
        }
        int currMatchIndex = findPref(nChoice, nPartner, hospitals, n);
        int nMatchCurrSIndex = findPref(nChoice, currStud, hospitals, n);
        if (currMatchIndex > nMatchCurrSIndex) {
            return false;
        }
    }
    return true;
}

bool verify(vector<pair<int,int>> matching, map<int, vector<int>> hospitals, map<int, vector<int>> students, int n, vector<pair<int, float>>& checkerTime) {
    auto start = chrono::high_resolution_clock::now();
    set<int> sCheck;
    set<int> hCheck;
    // verifies we see no duplicates in hospital or student matches
    // solves part a (example: hospital 1 and 2 cannot both match to student 2 because student 2 is listed once)
    for (auto i : matching) {
        if (sCheck.count(i.second) == 0) {
            sCheck.insert(i.second);
        } else {
            return false;
        }

        if (hCheck.count(i.first) == 0) {
            hCheck.insert(i.first);
        } else {
            auto stop = chrono::high_resolution_clock::now();
            // using default to get seconds
            chrono::duration<float> duration = stop - start;
            float elapsedTime = duration.count();
            return false;
        }
    }
    for (int i = 0 ; i < matching.size(); i++) {
        int currHosp = matching[i].first;
        int currStud = matching[i].second;
        int HospChoice = findPref(currHosp, currStud, hospitals, n); // finds what choice it's match is to it
        // Ex: finding hospital N is with 4th match, then HospChoice = 4
        int StudChoice = findPref(currStud, currHosp, students, n);
        if (HospChoice == 1 || StudChoice == 1) {
            continue; // at least one person in pair is super dooper happy and stable
        }
        else {
            if (!HappyH(currHosp, HospChoice, hospitals, students, matching,n) || !HappyS(currStud, StudChoice, hospitals, students, matching, n)) {
                cout << currHosp << " or " << currStud << " is unstable" << endl;
                auto stop = chrono::high_resolution_clock::now();
                // using default to get seconds
                chrono::duration<float> duration = stop - start;
                float elapsedTime = duration.count();
                return false;
            }
        }
    }
    auto stop = chrono::high_resolution_clock::now();
    // using default to get seconds
    chrono::duration<float> duration = stop - start;
    float elapsedTime = duration.count();
    checkerTime.push_back({n, elapsedTime});
    return true;

}
