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

    // find longest increasing and decreasing subsequence

    int n;
    cin >> n;

    int num_buildings;

    int n1 = 0;

    while (n1 < n){
        n1 ++;
        cin >> num_buildings;

        int heights[num_buildings];
        int widths[num_buildings];

        for (int i = 0; i < num_buildings; i++){
            cin >> heights[i];
        }
        for (int i = 0; i < num_buildings; i++){
            cin >> widths[i];
        }

        int longest_increasing;
        int longest_decreasing;

        




        cout << "Case " << n1 << ". ";
        if (longest_increasing > longest_decreasing){
            cout << "Increasing (" << longest_increasing << "). Decreasing (" << longest_decreasing << ").";
        }
        else{
            cout << "Decreasing (" << longest_decreasing << "). Increasing (" << longest_increasing << ").";
        }
        
    }

    
    return 0;
}
