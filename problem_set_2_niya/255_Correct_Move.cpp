#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
// #include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?
#include "../stdc++.h"

using namespace std;

int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    int king, queen, queenTo, diff;
    
    while (cin >> king >> queen >> queenTo)
    {
        if (king == queen)
        {
            cout << "Illegal state\n";
            continue;
        }
    
        if (((queenTo - queen) % 8 != 0 && queenTo / 8 != queen / 8) || queen == queenTo)
        {
            cout << "Illegal move\n";
            continue;
        }
        
        if (((king - queen) % 8 == 0 && (king - queenTo) % 8 == 0) || (king / 8 == queen / 8 && king  / 8 == queenTo / 8))
        {
            if (king <= max(queen, queenTo) && king >= min(queen, queenTo))
            {
                cout << "Illegal move\n";
                continue;
            }
        }
        
        diff = max(king, queenTo) - min(king, queenTo);
        
        if (diff == 8 || (diff == 1 && king / 8 == queenTo / 8))
        {
            cout << "Move not allowed\n";
            continue;
        }
        
        if ((king == 0 && queenTo == 9) || (king == 7 && queenTo == 14) || (king == 56 && queenTo == 49) || (king == 63 && queenTo == 54))
            cout << "Stop\n";
        
        else
            cout << "Continue\n";
    }

    
    return 0;
}
