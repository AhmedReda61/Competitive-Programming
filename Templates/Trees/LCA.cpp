#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 5 , Log = 23;

int anc[N][Log] , lvl[N];
vector<int> adj[N];

void buildAncestor(int u , int p) {

    lvl[u] = lvl[p]+1;
    anc[u][0] = p;
    for (int i = 1; i < Log ; ++i) {
        anc[u][i] = anc[anc[u][i-1]][i-1];
    }

    for (int v : adj[u]) {
        if (v == p)continue;
        buildAncestor(v , u);
    }

}

int kth_ancestor(int u , int k) {
    for (int i = 0; i < Log ; ++i) {
        if (k>>i & 1)u = anc[u][i];
    }
    return u;
}

int lca(int u , int v) {

    if (lvl[u] < lvl[v])swap(u , v);
    u = kth_ancestor(u , lvl[u] - lvl[v]);

    if (u == v)return u; // !!!
    for (int i = Log-1; i >= 0 ; --i) {
        if (anc[u][i] != anc[v][i])u = anc[u][i] , v = anc[v][i];
    }
    return anc[u][0];
}

int dist(int u , int v) {
    return lvl[u] + lvl[v] - 2*lca(u,v);
}