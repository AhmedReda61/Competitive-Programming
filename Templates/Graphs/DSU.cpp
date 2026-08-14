#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()

struct DSU {
    vector<int> par, rnk, sz;
    int c; // connected components;
    DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {
        iota(par.begin(),par.end(),0);
    }
    int find(int u) {
        return (par[u] == u ? u : (par[u] = find(par[u])));
    }
    bool same(int u, int v) {
        return find(u) == find(v);
    }
    int get_size(int u) {
        return sz[find(u)];
    }
    int merge(int u, int v) {
        if ((u = find(u)) == (v = find(v))) return 0;
        c--;
        if (rnk[u] < rnk[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        if (rnk[u] == rnk[v]) rnk[u]++;
        return u;
    }
};


ll kruskal(vector<array<int , 3>>& e , int n) { // O(E log(E))
    DSU d(n);
    sort(all(e));

    ll mst = 0;
    for (auto [c , u , v] : e) {
        if (d.merge(u,v))mst+=c;
    }
    return mst;
}

ll prim(vector<vector<array<int , 2>>>& adj , int n) {
    vector<bool> vis(n+1);
    ll mst = 0;
    set<array<int,2>> pq;// weight , u
    pq.insert({0,1});
    while (!pq.empty()) {
        auto [w,u] = *pq.begin();pq.erase(pq.begin());
        if (vis[u])continue;
        vis[u] = true , mst += w;
        for (auto [v,c] : adj[u]) {
            if (!vis[v]) pq.insert({c,v});
        }
    }
    return mst;
}

ll tree_diameter(vector<vector<int>>& adj , int n) { // p -> (a -> b) is tha max

    auto dist = [&](int s) {
        vector<int> d(n , -1);
        queue<int> q;
        q.push(s) , d[s] = 0;
        while (!q.empty()) {
            int u = q.front();q.pop();
            for (auto v : adj[u]) {
                if (d[v] != -1)continue;
                d[v] = 1 + d[u];
            }
        }
        return d;
    };

auto d0 = dist(0);
int a = max_element(begin(d0) , end(d0)) - begin(d0);
auto d1 = dist(a);
return *max_element(begin(d1) , end(d1));
}