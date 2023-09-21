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

    int n, d, r, result;

    while ( cin >> n >> d >> r){
       
        if (n == 0) break;
        result = 0;

        int morning[n];
        int afternoon[n];
        
        for (int i = 0; i < n; i++){
            cin >> morning[i];
        }

        for (int i = 0; i < n; i++){
            cin >> afternoon[i];
        }

        sort(morning, morning + n );
        sort(afternoon, afternoon + n, greater<int>());

        for (int i = 0; i < n; i++){
            int sum_hour = morning[i] + afternoon[i];
            if (sum_hour > d){
                result += (sum_hour - d) * r;
            }

        }

        cout << result << endl;

    }



    
    return 0;
}
