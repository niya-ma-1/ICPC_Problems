#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
// #include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?
#include "../stdc++.h"

using namespace std;

vector<vector<int>> graph;
vector<int> pred;

const int s = 1;
const int t = 2;

int n, m;
 
set<int> visited;



void dfs(int u){
    visited.insert(u);

}


int augment(int minBandwidth, int v){
    int u = pred[v];
    minBandwidth = min(minBandwidth, graph[u][v]);

    if (u != s)
        minBandwidth = augment(minBandwidth, u);

    graph[u][v] -= minBandwidth;
    graph[v][u] += minBandwidth;
    return minBandwidth;
}


int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //

    string line;

    while (cin >> n >> m){
        if (n == 0 && m == 0) break;

        graph.clear();
        graph.resize(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; ++i){
            int u, v, cost;

            cin >> u >> v >> cost;
            graph[u][v] = cost;
            graph[v][u] = cost;
        }

        vector<pair<int, int>> minCut;

        while (1){
            pred.clear();
            pred.resize(n + 1, -1);
            queue<int> q;

            pred[s] = s;
            q.push(s);
            while (!q.empty()){
                int u = q.front();
                q.pop();
                for (int v = 1; v <= n; ++v){
                    if (pred[v] == -1 && graph[u][v] > 0){
                        pred[v] = u;
                        q.push(v);
                    }
                }
            }

            if (pred[t] == -1) break;

            int minBandwidth = augment(INT_MAX, t);
            maxFlow += minBandwidth;
        }

    }


    
    return 0;
}
