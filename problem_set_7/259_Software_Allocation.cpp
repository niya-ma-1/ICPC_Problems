#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
// // #include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?
#include "../stdc++.h"

using namespace std;
#define INF 1e9
#define MAX_V 38

typedef vector<int> vi;
// graph
int graph[50][50];

// max flow, curr flow, source, sink/target
int mf,      f,         s,       t;
// augmenting paths
vi pred;
const int inf = 999;

// part of the Edmonds Karp algorithm
// v - current vertex, minEdge - min capacity along the path
void augment(int v, int minEdge){
    // when current vertex is the source node
    if(v == s){
        // set current flow to minEdge
        f = minEdge;
        return ;
    }
    // if there is a predecessor pred[v]
    else if(pred[v] != -1){
        // recursively call on the predesessor with the min flow
        augment(pred[v], min(minEdge, graph[pred[v]][v]));
        // subtract the current flow from the residual capacity of 
        // the edge (predecessor -> current vertex)
        graph[pred[v]][v] -= f;
        // adds curr flow to the residual capacity of the reverse edge
        graph[v][pred[v]] += f;
    }
}


int main(){
    char line[20], num[20];
    char c;
    int cnt, sum;
    while(1){
        if(feof(stdin)) break;
        // clear data for new testcase
        memset(graph, 0, sizeof(graph));
        s = 0; t = 37;
        sum = 0;
        while(cin.getline(line, 20)){
            if(line[0] == '\0') break;

            // connect source to each customer request
            sscanf(line, "%c%d %s", &c, &cnt, num);
            graph[s][c - 'A' + 1] = cnt;//起点连接程序
            sum += cnt;
            // connect customer request to computers
            for(int i = 0; num[i]; ++i)
                graph[c - 'A' + 1][num[i] - '0' + 27] = inf; //程序连接电脑
        }
        // connect computer to sink/target
        for(int i = 0; i < 10; ++i){
            graph[i + 27][t] = 1;//电脑连接终点
        }

        mf = 0;
        while(1){
            // initial flow is 0
            f = 0;//初始化最小边
        
            vi dist(38, inf); 
            dist[0] = 0;

            queue<int> q; 
            q.push(s);

            // initialize predecessor
            pred.assign(38, -1);

            // bfs
            while(!q.empty()){//BFS寻找s到t的路径
                int u = q.front(); 
                q.pop();

                // if current node is the target, then an augmenting path is found
                if(u == t) break;

                for(int v = 0; v < 38; v++){
                    // if there is residual capacity and distance to v is still infinity
                    if(graph[u][v] > 0 && dist[v] == inf){
                        dist[v] = dist[u] + 1;
                        q.push(v), pred[v] = u;
                    }
                        
                }
            }
            // after bfs completes, update the flow along the augmenting path, starting min capacity is inf
            augment(t, inf);//只要存在路径就可以得到最小边
            if(f == 0) break;
            // update max flow
            mf += f;//计算最大流
        }

        // if max flow doesn't equal total supply, then not possible to fulfill all customer requests
        if(mf != sum) cout << "!" << endl;
        else{
            // loop over computers
            for(int i = 27; i <= 36; i++){
                // sign is used to check whether a software is assigned to the current computer
                bool sign = true;
                // loop over softwares
                for(int j = 1; j <= 26 && sign; j++){
                    // check if flow on reverse edge
                    if(graph[i][j] > 0){//检测逆向边
                        cout << (char)(j - 1 + 'A');
                        sign = false;
                    }
                }
                if(sign) cout << '_';
            }
            cout << endl;
        }  
    }
}