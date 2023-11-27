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
    double x1, y1, x2, y2;

    while (cin >> x1 >> y1 >> x2 >> y2){
        double x3, y3, x4, y4;

        double xCenter = (x1 + x2) / 2;
        double yCenter = (y1 + y2) / 2;

        double xDiff = xCenter - x1;
        double yDiff = yCenter - y1;

        x3 = xCenter - yDiff;
        y3 = yCenter + xDiff;
        x4 = xCenter + yDiff;
        y4 = yCenter - xDiff;

        cout << fixed << setprecision(10) << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    }

    
    return 0;
}
