#include <bits/stdc++.h>
using namespace std;
#define ll long long

// O(Q√N) -> N <= 2e5;
constexpr int N = 2e5+1 , SQ = 450;

vector<ll> a;
vector<ll> b(SQ); // make sure that n/SQ < SQ !

void init() {
    for (int i = 0; i < a.size() ; ++i) {
        b[i/SQ] += a[i];
    }
}

void update(int i , ll x) {
    int blk = i/SQ;
    b[blk] -= a[i];
    a[i] = x;
    b[blk] += a[i];
}

ll query(int l , int r) {
    ll ret = 0;
    while(l <= r) {

        if (l%SQ == 0 && l+SQ-1 <= r) {
            ret += b[l/SQ];
            l += SQ;
        }else {
            ret += a[l];
            l++;
        }

    }
    return ret;
}