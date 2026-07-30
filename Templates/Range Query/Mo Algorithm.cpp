#include <bits/stdc++.h>
using namespace std;

constexpr int SQ = 175;
struct Query {
    int l,r,q_idx,blk_idx;
    Query() {}
    Query(int _l , int _r , int _q_idx) {
        l = _l , r = _r , q_idx = _q_idx , blk_idx = l/SQ;
    }

    bool operator<(const Query &q) const {
        if (blk_idx != q.blk_idx)return blk_idx < q.blk_idx;
        return r < q.r;
    }

};

vector<Query> Q;
vector<int> ans;
int res = 0;

vector<int> f,a;

void add(int i) { // To be modified
    f[a[i]]++;
    if (f[a[i]] == 1)res++;
}

void remove(int i) { // To be modified
    f[a[i]]--;
    if (f[a[i]] == 0)res--;
}

void MO_process() {
    sort(Q.begin() , Q.end());
    int l = 1 , r = 0; // 0-base
    for (int i = 0; i < Q.size() ; ++i) {
        while (l < Q[i].l)remove(l++);
        while (l > Q[i].l)add(--l);
        while (r < Q[i].r)add(++r);
        while (r > Q[i].r)remove(r--);
        ans[Q[i].q_idx] = res;
    }
}