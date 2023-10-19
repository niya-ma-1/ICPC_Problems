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
    int N, M, numInstructions;

    while (cin >> N >> M >> numInstructions){

        int result = 0;

        if (N == 0 || M == 0 || numInstructions == 0){
            return 0;
        }

        char grid[N][M];
        memset(grid, 0, sizeof (grid));

        char currCell;
        int currI, currJ;
        // direction, north is 0, east is 1, south is 2, west is 3
        int currDir;
        for ( int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                cin >> currCell;

                if (currCell == 'N' || currCell == 'E' || currCell == 'S' || currCell == 'O'){
                    currI = i;
                    currJ = j;
                }

                if (currCell == 'N') currDir = 0;
                else if (currCell == 'E') currDir = 1;
                else if (currCell == 'S') currDir = 2;
                else if (currCell == 'O') currDir = 3;
                
                grid[i][j] = currCell;
                
            }
        }

        string instructions;

        cin >> instructions;

        for (char instruction : instructions){
            // turn right
            if (instruction == 'D'){
                currDir = (currDir + 1) % 4;
            }
            else if ( instruction == 'E'){
                currDir = (currDir - 1 + 4) % 4;
            }
            else{
                int newI = currI;
                int newJ = currJ;
                if (currDir == 0) newI--;
                else if (currDir == 1) newJ++;
                else if (currDir == 2) newI++;
                else if (currDir == 3) newJ--;
                if (newI >= 0 && newI < N && newJ >0 && newJ < M && grid[newI][newJ] != '#'){
                    currI = newI;
                    currJ = newJ;
                }
            }
            if (grid[currI][currJ] == '*'){
                result++;
                grid[currI][currJ] = '.';
            }
            // cout << "Instruction " << instruction << " new positions " << currI << currJ  << " new dir " << currDir<< endl;
        }

        cout << result << endl;
    }
    
    return 0;
}
