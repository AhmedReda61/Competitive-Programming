#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define print(x) for(auto i : x)cout<<i<<" ";cout<<nl
#define take(x) for(auto &i : x)cin>>i
#define all(x) x.begin(), x.end()
constexpr char nl = '\n';
constexpr int mod = 1000000007;

struct edge {
    int idx;ll cost;
    friend bool operator<(const edge& a ,const edge& b) {
        return a.cost > b.cost;
    }
};

int N;
vector<vector<edge>> adj;
vector<ll> dist;
vector<int> parent;// for printing the path


void dijkstra(int s , vector<int>& init) { // O( E log(E) ) // init for multiple sources

        dist[s] = 0;

    priority_queue<edge> pq;
    pq.push({s,0});

    //for (int i : init)dist[i] = 0 , pq.push({i,0});


    while(!pq.empty()) {

        auto curr = pq.top();pq.pop();

        if (curr.cost > dist[curr.idx])continue; // hence, you calculated before;

        for (auto nxt : adj[curr.idx]){
            if (dist[nxt.idx]==-1||nxt.cost + curr.cost< dist[nxt.idx]) {

                dist[nxt.idx] = curr.cost + nxt.cost;
                pq.push({nxt.idx,dist[nxt.idx]});

                //parent[nxt.idx] = curr.idx;
            }
        }
    }
}





void fast();
signed main() {
    fast();

    int M;cin >> N >> M;

    adj.resize(N+1);
    dist.resize(N+1,-1);


    while (M--){
        int u,v,w;cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

}
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
