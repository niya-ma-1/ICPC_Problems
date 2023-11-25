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

    int numTestcases;
    cin >> numTestcases;
    int numCities, threshold;
    vector<pair<int, int>> cities;

    vector<pair<double, pair<int, int>>> edges;

    int tempI, tempJ;

    for (int n1 = 1; n1 <= numTestcases; n1++){
        parents.clear();
        cities.clear();
        edges.clear();

        cin >> numCities >> threshold;

        double distRoads = 0;
        double distRails = 0;

        int numRoads = 0;

        for (int i = 0; i < numCities; i++){
            cin >> tempI >> tempJ;
            cities.push_back(make_pair(tempI, tempJ));
            parents.push_back(i);
        }

        // // we want to find the minimum spanning tree
        // // each edge <=  threshold is a road (within a city)
        // // each edge > threshold is a rail ( between cities)

        // // for each pair of points, make an edge between
        for (int i = 0; i < numCities; i++){
            for (int j = i + 1; j < numCities; j++){
                pair<int, int> u = cities[i];
                pair<int, int> v = cities[j];

                double dist = sqrt(
                    pow(
                        ( (int)u.first - (int)v.first ), 
                        2) + 
                    pow(
                        ((int)u.second - (int)v.second), 
                        2) );
               
                edges.push_back(make_pair(dist, make_pair(i, j)));
            }
        }

        sort(edges.begin(), edges.end(), 
                [](const pair<double, pair<int, int>> a, pair<double, pair<int, int>> b) 
                {return a.first < b.first; });

        int numStates = 1;

        for (pair<double, pair<int, int>> edge : edges){
            double dist = edge.first;

            int u = edge.second.first;
            int v = edge.second.second;

            int parentu = findParent(u);
            int parentv = findParent(v);

            if (parentu == parentv) continue;

            unionElements(parentu, parentv);
            numRoads ++;

            if (dist <= threshold){
                distRoads += dist;
            }
            else {
                distRails += dist;
                numStates ++;
            }
            
            if (numRoads == numCities - 1) break;
        }

        cout << "Case #"<< n1 << ": " << numStates << " " << (int)round(distRoads) << " " <<  (int)round(distRails) << endl;

    }

    
    return 0;
}
