#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <set>

using namespace std;

bool prefers(int a, int h, map<int, vector<int>> students,  vector<pair<int, int>> matching){
    int currMatch = 0;
    int matchInd = -1;
    int n = students.size();
    // find the current hospital for that student
    for (int i = 0; i<matching.size(); i++){
        if (a == matching[i].second){
            currMatch = matching[i].first; //hospital that student 'a' is paired to in the matching list
        }
    }
    // what number preference is this matched hospital
    for (int i = 0; i<n; i++){
        if (students[a][i]==currMatch){
            matchInd = i;
        }
    }
    // compare with student preference list
    int i = 0;
    while (i<matchInd){
        if (students[a][i] == h){
            return true;
        }
        i++;
    }
    return false;
}

vector<pair<int,int>> matcher(map<int, vector<int>> hospitals, map<int, vector<int>> students, int n){
    vector<pair<int, int>> matching;
    set<int> available;
    queue<int> pending;
    // create a hospitals pending queue [1,2,3]
    for (int i=1; i<=n; i++){
        pending.push(i);
        available.emplace(i);
    }

    while (!pending.empty()){
        int currHosp = pending.front();
        for (int i = 0; i<n; i++) { //loops through preference list
            if (available.count(hospitals[currHosp][i])!=0){
                // student is free (in the available list)
                matching.push_back({currHosp, hospitals[currHosp][i]}); // match made!!
                pending.pop(); // take hospital out the queue
                available.erase(hospitals[currHosp][i]); // student is taken
                break; // no more students to loop through, hospital is satisfied
            }
            else if(prefers(hospitals[currHosp][i], currHosp, students, matching)){
                for (int j=0; j<matching.size(); j++){
                    if (matching[j].second == hospitals[currHosp][i]){ // find old hospital pairing
                        pending.push(matching[j].first); // put it back in the queue, needs a student again
                        matching[j].first = currHosp; // update the match with the new hospital
                        pending.pop(); // take the new hospital out the queue
                        break;
                    }
                }
                break; // no more students to loop through
            }
            else{
                continue; // a rejects h
            }
        }
    }
    sort(matching.begin(), matching.end());
    // write to output file
    string fileName = "";
    fileName = "../outputs/example" + to_string(n) + "out.txt";
    ofstream outFile(fileName);
    if (!outFile.is_open())
    {
        cout << "Error in creating file!" << endl;

    }
    else {
        for (int i = 0; i<n; i++){
            // write pairing to example_out.txt
            outFile << matching[i].first << " "<< matching[i].second << "\n";
        }
        outFile.close();
    }
    return matching;
}

