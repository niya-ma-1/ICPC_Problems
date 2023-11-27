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
    string line;

    while (getline(cin, line)){
        if (isdigit(line[0])){
            reverse(line.begin(), line.end());

            string ascii = "";
            string decodedLine = "";

            int i = 0;
            while (i < line.length()){
                if (line[i] == '1'){
                    ascii += line[i];
                    ascii += line[i+1];
                    ascii += line[i+2];
                    i += 3;
                }
                else{
                    ascii += line[i];
                    ascii += line[i+1];
                    i += 2;
                }
                
                decodedLine += static_cast<char>(stoi(ascii));
                ascii = "";
            }
            cout << decodedLine << endl;
            
        } else {
            string encodedLine = "";
            for(int i = 0; i < line.length(); i++){
                encodedLine += to_string((int)line[i]);
            }
            reverse(encodedLine.begin(), encodedLine.end());

            cout << encodedLine << endl;
        }
    }
    
    return 0;
}

