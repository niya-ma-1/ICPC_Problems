#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static const int MAX_BANDWIDTH = 1000;
vector<vector<int> > graph;
vector<int> pred;

int s, t, c;

// Return the minimal bandwidth of the path from s to v.


int augment(int minBandwidth, int v){
    int u = pred[v];
    minBandwidth = min(minBandwidth, graph[u][v]);

    if (u != s)
        minBandwidth = augment(minBandwidth, u);

    graph[u][v] -= minBandwidth;
    graph[v][u] += minBandwidth;
    return minBandwidth;
}

int main()
{    
    int num_case = 1, n;
    while (cin >> n, n != 0)
    {   
        graph.clear();
        graph.resize(n + 1, vector<int>(n + 1, 0));
    

        cin >> s >> t >> c;
        for (int i = 1; i <= c; ++i)
        {
            int u, v, bandwidth;
            cin >> u >> v >> bandwidth;
            
            graph[u][v] += bandwidth;
            graph[v][u] += bandwidth;
        }

        int maxFlow = 0;
        while (1)
        {
            
            pred.clear();
            pred.resize(n + 1, -1); 
            queue<int> q;
        
            pred[s] = s;
            q.push(s);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v = 1; v <= n; ++v)
                    if (graph[u][v] > 0 && pred[v] == -1)
                    {
                        pred[v] = u;
                        q.push(v);
                    }
            }
            if (pred[t] == -1)
                break;

            maxFlow += augment(MAX_BANDWIDTH,t);
        }
        cout << "Network " << num_case++ << endl;
        cout << "The bandwidth is " << maxFlow << "." << endl ;
    }
    return 0;
}