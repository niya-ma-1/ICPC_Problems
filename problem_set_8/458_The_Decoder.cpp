#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
// #include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?
#include "../stdc++.h"

using namespace std;

int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //
    string line;
    while (cin >> line){
        for (int i = 0; i < line.length(); i++){
            cout << (char)(line[i] - 7);
        }
        cout << endl;
    }

    
    return 0;
}


