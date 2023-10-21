#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
// #include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?
#include "../stdc++.h"



// DOES NOT WORK


using namespace std;

int main(){

    //
    // Get the case number.
    int n;
    cin >> n;
    string line;
    //
    // ignore first line with \n
    getline(cin, line); 
    while (n--){
        //
        // ignore first line with \n
        getline(cin, line); 
        //
        // Names of the vertecies (A B C).
        getline(cin, line);
        string vertexNames = line;
        //
        // The edge list (A<B, and so on)
        getline(cin, line);
        string edges = line;

        //
        // Create an adj list.
        map<char, unordered_set<char>> adjList;
        
        //
        // Iterate over each vertex, create a list for it.
        istringstream iss(vertexNames);
        string currElement;
        while (iss >> currElement){
            adjList[currElement[0]] = unordered_set<char>();
        }

        //
        // Populate the lists in the adjList
        iss.clear();
        iss.str(edges);
        while (iss >> currElement){
            char a = currElement[0];
            char b = currElement[2];
            adjList[a].insert(b); // could there be duplicates?
        }
       

        vector<string> results;
        results.clear();
        results.push_back("");
        vector<char> curr_level;
        
        int remaining = adjList.size();

        while (remaining){
            
            curr_level.clear();

            // find verteces with value of empty set (no outgoing edge)

            for ( auto& entry : adjList){
                if (entry.second.empty()){
                    curr_level.push_back(entry.first);
                    remaining --;
                }
            }

            vector<string> new_results;
            new_results.clear();

            for (char vertex : curr_level){
                for ( auto& entry : adjList){
                    entry.second.erase(vertex);
                }
                
                for (string& result: results){
                    
                    string new_result = result + vertex;
                    cout << "new result " << new_result << endl;
                    new_results.push_back(new_result);
                }
            }

            results = new_results;

        }

        for (string& result : results){
            // if (result.length() == adjList.size())
            cout << result << endl;
        }

    }


    
    return 0;
}

