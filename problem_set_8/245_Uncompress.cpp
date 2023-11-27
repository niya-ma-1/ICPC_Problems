#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
// #include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?
#include "../stdc++.h"

using namespace std;

vector<string> wordList;

void printWord(string word){
    cout << word;
    if (wordList.empty()){
        wordList.push_back(word);
    }
    else{
        wordList.push_back(wordList.back());
        for (int i = wordList.size() - 2; i > 0; i--){
            wordList[i] = wordList[i - 1];
        }
        wordList[0] = word;
    }
}

void printIndex(int num){
    string word = wordList[num - 1];
    cout << word;
    for (int i = num - 1; i > 0; i--){
        wordList[i] = wordList[i - 1];
    }
    wordList[0] = word;
}

int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //
    string line;

    while (getline(cin, line)){
        
        if (line == "0") break;
        line += "\n";
        
        string word = "";
        int idx = 0;

        for (int i = 0; i < line.size(); i++){
            
            if (isalpha(line[i])){
                word += line[i];
            }
            else if (isdigit(line[i])){
                idx *= 10;
                idx += line[i] - '0';
            }
            else{
                if (idx) printIndex(idx);
                if (word != "") printWord(word);
                word = "";
                idx = 0;
                cout << line[i];
            }
        }

    }
    
    
    return 0;
}
