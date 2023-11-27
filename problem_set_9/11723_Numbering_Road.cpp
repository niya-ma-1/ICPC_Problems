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

    int r, n;
    int caseNum = 1;

    while (cin >> r >> n && (r != 0 && n != 0)){
        r--;
        int result = r / n;

        if (result <= 26){
            cout << "Case " << caseNum << ": " << result << endl;
        }
        else{
            cout << "Case " << caseNum << ": impossible" << endl;
        }
        caseNum ++;
    }
    
    return 0;
}
