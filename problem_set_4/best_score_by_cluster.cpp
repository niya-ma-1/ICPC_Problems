#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
// #include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?
#include "../stdc++.h"

using namespace std;

// input format
// 5
// A B 0.1
// C B 0.2
// D F 1.1
// D C 2.0
// X Y 1.1

// A B 0.1 means A's score is 0.1 better than B (i.e A = 1.1 B)
// We want the highest score by cluster, in this case, we have 2 clusters 
// A B C D F, and X Y

// first create an adjacency map
// We first find the clusters based using dfs
// Then for each cluster, find the maximum node

int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //

    int n;

    cin >> n;

    string entry[3];

    while (--n){
        cin >> entry[0] >> entry[1] >> entry[2];
    }
    


    
    return 0;
}
