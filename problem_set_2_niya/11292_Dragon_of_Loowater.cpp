#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
// #include "../stdc++.h" // Compilation time is not counted. So why bother writing all the imports?
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;

int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //

    int n, m, gold;

    while (cin >> n >> m && !(n==0 &&m==0)){
        gold = 0;

        int dragons[n];
        int knights[m];

        for (int i = 0; i < n; i++){
            cin >> dragons[i];
        }

        for (int i = 0; i < m; i++){
            cin >> knights[i];
        }

        if (n > m){
            cout << "Loowater is doomed!" << endl;
            continue;
        }

        sort(dragons, dragons + sizeof(dragons) / sizeof(dragons[0]));
        sort(knights, knights + sizeof(knights) / sizeof(knights[0]));

        for (int i = 0; i < n; i++){
            if (dragons[i] > knights[i]){
                cout << "Loowater is doomed!" << endl;
                continue;
            }
            gold += knights[i];
        }
        cout << gold << endl;
    }




    
    return 0;
}
