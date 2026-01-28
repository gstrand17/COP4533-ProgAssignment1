#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
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

bool verify(vector<pair<int,int>> matching, map<int, vector<int>> hospitals, map<int, vector<int>> students, int n) {
    set<int> sCheck;
    set<int> hCheck;
    // verifies we see no duplicates in hospital or student matches
    // solves part a (example: hospital 1 and 2 cannot both match to student 2 because student 2 is listed once)
    for (auto i : matching) {
        if (sCheck.count(i.second()) == 0) {
            sCheck.insert(i.second());
        } else {
            return false;
        }

        if (hCheck.count(i.first()) == 0) {
            hCheck.insert(i.first());
        } else {
            return false;
        }
    }

}
