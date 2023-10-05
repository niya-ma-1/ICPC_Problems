// 1 case number
// 5 6 15  N (length), M(width), K (money)
// 10 1  10 20 10 10  price of P_i,j
// 30 1  1  5  1  1
// 50 1  1  20 1  1
// 10 5  5  10 5  1
// 40 10 90 1  10 10

// Find the largest affordable rectangle, if two rectangle are the 
// same size and both affordable, choose the cheaper one
// 
// output: Case #1: 6 10   rectangle size, price


// 2-d DP?

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

    int n_testcases;
    // sliding 2-d window
    cin >> n_testcases;

    int i = 1;
    int k = 1;

    while (n_testcases--){

        int n, m, budget;
        cin >> n >> m >> budget;

        int prefixSum[n+1][m+1];
        memset(prefixSum, 0, sizeof prefixSum);
        int curr;

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> curr;
                prefixSum[i][j] = curr + prefixSum[i-1][j];
            }
        }

        int currCost, currArea, area = 0, cost = 0, c1;

        for (int r1 = 1; r1 <= n; r1++){
            for (int r2 = r1; r2 <= n; r2++){
                c1 = 1;
                currCost = 0;
                for (int c2 = 1; c2 <= m; c2++){
                    currCost += prefixSum[r2][c2] - prefixSum[r1-1][c2];

                    while (currCost > budget && c1 <= c2){
                        currCost -= prefixSum[r2][c1] - prefixSum[r1-1][c1];
                        c1++;
                    }

                    currArea = (r2-r1+1)*(c2-c1+1);
                    if (currArea > area || (currArea == area && currCost < cost)){
                        area = currArea;
                        cost = currCost;
                    }
                                                

            }

            }
        }
        cout << "Case #" << i++ << ": " << area  << " "<< cost << endl; 
    }

    return 0;
}
