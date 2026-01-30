#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

void shuffle(vector<int>& nRange){
    for (int i = nRange.size() - 1; i >= 1; i--) {
        int j = rand() % (i + 1);
        int temp = nRange[i];
        nRange[i] = nRange[j];
        nRange[j] = temp;
    }
}

vector<string> generator(vector<int> nArray){ // where nArray = [1,2,4, 8, 16, 32, 64, 128, 256, 512]
    vector<string> fileList;
    string fileName = "";
    // generate one file per n
    for (int i = 0; i<nArray.size(); i++){
        int n = nArray[i];
        if (n<1){ // does not generate a test file for an invalid n
            continue;
        }
        fileName = "../inputs/example" + to_string(n) + "in.txt"; // for n = 512, file name is example512in.txt
        ofstream outFile(fileName);
        if (!outFile.is_open()){
            cout << "Error in creating file!" << endl;
        } else{
            fileList.push_back(fileName);
            outFile << to_string(n) << "\n"; // first write 'n' to the test file and new line
            vector<int> nRange; //define an array of n size to be used for permutations of preference numbers
            srand(time(NULL));
            for (int j = 1; j<=n; j++){
                nRange.push_back(j); // load in all values 1-n to nRange
            }
            for (int k = 0; k<n*2; k++){
                shuffle(nRange); // create a permutation of 1-n
                for (int m=0; m<n-1; m++){
                    outFile << nRange[m] << " "; // write one number and a space
                }
                outFile << nRange[n-1] << "\n"; // write the last number and a new line
            }
        }

        outFile.close();
    }
    return fileList;
}


