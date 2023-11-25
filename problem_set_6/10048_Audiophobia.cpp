#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
// #include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?
#include "../stdc++.h"

using namespace std;

vector<int> parents;

inline int findParent(int element){
    if (parents[element] == element) return element;
    return findParent(parents[element]);
}

inline void unionElements(int element1, int element2){
    int parent1 = findParent(element1);
    int parent2 = findParent(element2);

    parents[parent1] = parent2;
}



int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //

    int numVertices, numEdges, numQueries;
    int numCase = 1;

    vector<pair<int, pair<int, int>>> edges;


    while (cin >> numVertices >> numEdges >> numQueries){
        parents.clear();

        if (numVertices == 0 && numEdges == 0 && numQueries == 0){
            break;
        }
        if(numCase != 1) cout << endl;

        int c1, c2, d;

        edges.clear();

        int numEdges2 = numEdges;
        while (numEdges2--){
            cin >> c1 >> c2 >> d;
            edges.push_back(make_pair(d, make_pair(c1-1, c2-1)));
        }

        for (int i = 0; i < numVertices; i++){
            parents.push_back(i);
        }

        // make the min spanning tree
        sort(edges.begin(), edges.end(), 
                [](const pair<double, pair<int, int>> a, pair<double, pair<int, int>> b) 
                {return a.first < b.first; });



        // make minimum spanning tree
        int connectedVertices = 0;
        map<int, vector<pair<int, int>>> mstAdjlist;


        for (int i =0; i < numEdges; i++){
            
            // all vertices connected, we are done
            if (connectedVertices == numVertices - 1) break;
            
            int parent1 = findParent(edges[i].second.first);
            int parent2 = findParent(edges[i].second.second);


            // if these two are alredy connected
            if (parent1 == parent2) continue;

            unionElements(parent1, parent2);
            connectedVertices ++;

            // add to adj list, value is  pair( edge value, other vertex)
            mstAdjlist[edges[i].second.first].push_back(make_pair(edges[i].first, edges[i].second.second));
            mstAdjlist[edges[i].second.second].push_back(make_pair(edges[i].first, edges[i].second.first));
        
        }


        cout << "Case #" << numCase << endl;

        for (int i = 0; i < numQueries; ++i){

            int queryI, queryJ;
            cin >> queryI >> queryJ;

            queryI --;
            queryJ --;

            if (findParent(queryI) != findParent(queryJ)){
                cout << "no path" << "\n";
                continue;
            }

            queue<pair<int,int>> q;
            q.push({0,queryI});
            vector<bool> visited(numVertices, false);
            visited[queryI] = true;

            while (!q.empty()){
                pair<int, int> curr = q.front();
                q.pop();

                if(curr.second == queryJ){
                    cout << curr.first << "\n";
                    break;
                }

                for (pair<int, int> neighbor : mstAdjlist[curr.second]){
                    if (!visited[neighbor.second]){
                        visited[neighbor.second] = true;

                        int maxWeight = max(curr.first, neighbor.first);
                        q.push({maxWeight, neighbor.second});
                    }
                }
            }            
        }
        numCase ++;
    }

    return 0;
}
