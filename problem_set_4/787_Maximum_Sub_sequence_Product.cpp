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

    int nums[100];

    int curr, idx, negMin, posMax, result, temp;
    
    idx = 0;
    while (cin >> curr){
        if (curr != -999999){
            nums[idx++] = curr;
        }
        else{
            negMin = posMax = result = nums[0];

            for (int i = 1; i < idx; i ++){
                curr = nums[i];
                temp = posMax;

                posMax = max(curr, max(curr * temp, curr * negMin));
                negMin = min(curr, min(curr * temp, curr * negMin));

                result = max(posMax, result);
            }
            idx = 0;
            cout << result << endl;
        }
    }

    return 0;
}
