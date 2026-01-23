#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <set>
using namespace std;

void matcher(map<int, vector<int>> hospitals, map<int, vector<int>> students, int n){
    vector<pair<int, int>> matching;
    set<int> available;
    queue<int> pending;
    // create a hospitals pending queue [1,2,3]
    for (int i=1; i<=n; i++){
        pending.push(i);
        available.emplace(i);
    }

    while (!pending.empty()){
        int num = pending.front();
        for (int i = 0; i<n; i++){
            if (available.count(hospitals[num][i])==0){
                // student is free
                matching.push_back({num, i}); // match made
                pending.pop(); // hospital doesn't need a student any longer
                available.erase(i); // student is no longer available
            }
            else if(){

            }
        }



    }
}

