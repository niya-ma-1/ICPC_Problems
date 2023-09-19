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

    int n_test_cases;
    cin >> n_test_cases;

    while (n_test_cases--){
        
        int n_types;
        cin >> n_types;
        vector<int> values;

        for (int i = 0; i < n_types; i++){
            int value;
            cin >> value;
            values.push_back(value);
        }

        int sum = 1;
        int coins = values.size() > 1? 2 : 1;

        for (int i = 1; i < values.size()-1; ++i){
            if (sum + values[i] < values[i+1]){
                sum += values[i];
                ++coins;
            }
        }

        cout << coins << endl;
    }
    return 0;
}
