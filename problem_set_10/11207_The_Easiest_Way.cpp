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

    int numPaper;
    double w, h;

    while (cin >> numPaper){
        if (numPaper == 0){
            break;
        }

        double maxSize = 0;
        int maxNum = 1;

        int num = 1;
        while (numPaper--){
            cin >> w >> h;
            double size = max(max(min(w, h/4), min(w/4, h)), min(h/2, w/2));
            // cout << " size: " << size << endl;
            if (size > maxSize){
                maxSize = size;
                maxNum = num;
            }
            num ++; 
        }
        cout << maxNum << endl;
    }

    return 0;
}
