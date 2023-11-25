#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
// #include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?
#include "../stdc++.h"

using namespace std;

int N = 100;
int INF = 5000;

int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    //

    int num_case = 1;
    int a, b;
    while (cin >> a >> b ){
        if (a == 0 && b == 0) break;

        vector<vector<int>> adjList(N+1, vector<int>(N+1, INF));

        int n = 0; 

        while (a && b){

            adjList[a][b] = 1;

            cin >> a >> b;
        }

        for (int k = 1; k <= N; k++){
            for (int i = 1; i <= N; i++){
                for (int j = 1; j <= N; j++){
                    adjList[i][j] = min(adjList[i][j], adjList[i][k] + adjList[k][j]);
                }
            }
        }

        int sum = 0;
        int count = 0;
        for (int i = 0; i <= N; i++){
            for (int j = 1; j <= N; j++){
                if (i != j && adjList[i][j] != INF){
                    sum += adjList[i][j];
                    count ++;
                }
            }
        }

        cout << "Case " << num_case++ << ": average length between pages = " << setprecision(3) << fixed << (double)sum/count << " clicks" << endl;

    }

    
    return 0;
}
