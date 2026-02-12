#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define print(x) for(auto i : x)cout<<i<<" ";cout<<nl
#define take(x) for(auto &i : x)cin>>i
#define all(x) x.begin(), x.end()
constexpr char nl = '\n';

ll hash (string& s) {
    int p = 31 , m = 1e9 + 9;
    ll ans = 0 , pow = 1;

    for (char c : s) {
        ans = (ans  + (c - '0' + 1) * pow) % m;
        pow = (pow * p) % m;
    }
    return ans;
}

vector<ll> prefix_hash (string& s) {
    int n = s.size() , p = 31 , m = 1e9 + 9;
    vector<ll> pow(n);
    pow[0] = 1;
    for (int i = 1; i < n ; ++i)pow[i] = (pow[i-1] * p) % m;

    vector<ll> ans(n+1); // 1-based

    for (int i = 0; i < n ; ++i)
        ans[i+1] = (ans[i] + (s[i] - '0' + 1) * pow[i]) % m;

    /*
     hash(l,r) * pow[l] = (ans[r+1] - ans[l] + m) % m;
     # You can multiply by a fixed power like pow[n-1 - l];
     */

    return ans;
}

vector<ll> multiset_hashing (vector<int>& a) {
    int n = a.size() , p = 1e9 + 7 , m = 1e9 + 9;
    vector<ll> pow(n);
    pow[0] = 1;
    for (int i = 1; i < n ; ++i)pow[i] = (pow[i-1] * p) % m;
    // a[i] must be < n <= 2e5; "coordinate compression"
    vector<ll> ans(n+1);
    for (int i = 0; i < n ; ++i)
        ans[i+1] = (ans[i] + pow[a[i]]) % m;
    /*
     You don't need to multiply by a fixed power anymore;
     "https://atcoder.jp/contests/abc367/tasks/abc367_f"
     */
    return ans;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
T rand(T l, T r) {return uniform_int_distribution<T>(l, r)(rng);}

vector<ll> xor_hashing (vector<int>& a) {
    int n = a.size();
    vector<ll> h(n+1);
    for (int i = 0; i <= n ; ++i)h[i] = rand<ll>(1,1e18);

    vector<ll> ans(n+1);
    for (int i = 0; i < n ; ++i)ans[i+1] = (ans[i] ^ h[a[i]]);

    /*
     "https://codeforces.com/problemset/problem/2014/H"
     "https://atcoder.jp/contests/abc250/tasks/abc250_e"
     */

    return ans;
}

struct Hash {
    int n,p,m;
    vector<ll> pow{1} , pref{0};
    Hash(){}
    Hash(string& s , int _p , int _m) {
        n = s.size() , p = _p , m = _m;

        for (int i = 0; i < n ; ++i) {
            pow.push_back(pow.back() * p % m);
            pref.push_back((pref.back() + (s[i] - '0' + 1)*pow[i]) % m);
        }
    }

    ll get (int l , int r) {
        return (pref[r+1] - pref[l] + m) % m; // => hash(l,r) * pow[l]; !!
    }

};

struct double_hash {
    Hash h1,h2;
    double_hash(string& s , int p1 , int m1 , int p2 , int m2) {
        h1 = Hash(s,p1,m1);
        h2 = Hash(s,p2,m2);
    }
    pair<ll,ll> get(int l , int r) {
        return { h1.get(l,r) , h2.get(l,r) };
    }
};




void fast();
signed main() {
    fast();
}


void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
