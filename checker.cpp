#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

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
