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
    int numCase;

    cin >> numCase;

    double d, v, u;

    for (int i = 1; i <= numCase; i++){
        cin >> d >> v >> u;

        if (v >= u || u == 0){
            cout << "Case " << i << ": " << "can't determine" << endl;
            continue;
        }

        double way1 = d / u;
        double way2 = d / sqrt( pow(u,2) - pow(v,2));

        if (way1 == way2){
            cout << "Case " << i << ": " << "can't determine" << endl;
            continue;
        }


        cout << "Case " << i << ": " << setprecision(3) << fixed << way2 -way1 << endl;
    }

    
    return 0;
}
