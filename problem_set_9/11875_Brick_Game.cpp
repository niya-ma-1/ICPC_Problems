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

    int numCases;
    string line;
    vector<int> players;
    int age;
    int numPlayers;

    cin >> numCases;

    for (int n = 1; n <= numCases; n ++){
        players.clear();

        cin >> numPlayers;
        for (int i = 0; i < numPlayers; i++){
            cin >> age;
            players.push_back(age);
        }

        sort(players.begin(), players.end());


        cout << "Case " << n << ": " << players[numPlayers / 2] << endl;
    }

    
    return 0;
}
