#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj(n+1);
vector<vector<pair<int,int>>> adj_w(n+1);
map<int,vector<int>> adj2;// if n>1e8;
vector<string> adjmat;// if the input is array of string "implicit graph";

vector<bool> vis(n+1);

vector<int> parent(n+1);// to print the path && make the root = 0;
// & is used for get the shortest path for unweighted graph using "bfs";


void dfs(int u) {
    vis[u] = true;

    for(auto v : adj[u]) {
        if(!vis[v]) {

            dfs(v);
        }
    }
}

void bfs(int start) {

    queue<int> q;
    q.push(start);
    vis[start] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto v : adj[u]) {
            if(!vis[v]) {
                q.push(v) , vis[v] = true;

            }
        }
    }
}

// Flood Fill
int N,M; // row,col
vector<vector<bool>> visted(N,vector<bool>(M));

vector<int> dx {1,-1,0,0},dy {0,0,1,-1};// S , N , E , W
// S,N,E,W,SE,SW,NE,NW (size = 8)
vector<int> dr {1,-1,0,0,1,1,-1,-1};  // row
vector<int> dc {0,0,1,-1,1,-1,1,-1}; // col

bool valid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}
void flood_fill(int x, int y) {
    if (!valid(x, y))return;
    visted[x][y] = true;
    for (int i = 0; i < 4; ++i){
        int ii = x + dx[i] , jj = y + dy[i];
        if (!visted[ii][jj]) {
            flood_fill(ii, jj);

        }
    }
}

//Topological Sort

vector<int> in(n+1);

void topo_sort(){

    priority_queue<int, vector<int>, greater<int> > pq;// for minimal answer
    for (int u = 0; u < n; ++u)
        if (in[u] == 0)pq.push(u);

    while (!pq.empty()) {
        int u = pq.top();pq.pop();
        for (auto v: adj[u]) {
            in[v]--;
            if (in[v] > 0) continue;
            pq.push(v);
        }
    }
}

//Bipartite
bool check(int s) {
    queue<int> q;q.push(s);
    vector<int> color(n, -1);color[s] = 0;
    while (!q.empty()) {
        int u = q.front();q.pop();
        for (auto v: adj[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            } else if (color[v] == color[u]) {
                return false;
            }
        }
    }
    return true;
}