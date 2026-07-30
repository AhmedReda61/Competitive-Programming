#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int mod = 1e9 + 7;

ll fpow(ll a, ll b , ll m = mod) {
    ll res = 1;
    for (a%=m ; b ; a =a*a%m , b>>=1)if (b&1)res = res*a%m;
    return res;
}
//	O(log(mod)), mod has to be prime
ll inv(ll a) {
    return fpow(a, mod - 2 , mod);
}

const int N = 3e6 + 10;
ll fact[N] , inv_fact[N];
void pre_fac() {
    fact[0]=fact[1]=1;
    for (ll i=2;i<N;i++) {
        fact[i]= i * fact[i-1] % mod;
    }
    inv_fact[N-1]=inv(fact[N-1]);
    for (ll i=N-2;i>=0;i--) {
        inv_fact[i] = (i+1) * inv_fact[i+1] % mod;
    }
}

ll nCr(ll n,ll r) {
    if (r<0 || r>n) return 0;
    return fact[n]*inv_fact[r] % mod * inv_fact[n-r] % mod;
}

ll nPr(ll n,ll r) {
    if (r<0 || r>n) return 0;
    return fact[n] * inv_fact[n-r] % mod;
}

ll C[3001][3001];
void pre_C() {
    for (int i = 0; i <= 3e3; ++i) {
        C[i][0] = 1;  // nC0 = 1
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }
}

ll nCr_loop(ll n , ll r) { // n-r <= 2e6
    ll ans = 1;
    for (ll i = r+1; i <= n ; ++i) { // n!/r! = (r+1) * (r+2) ... * n && (i-r) -> 1 * 2 ... * (n-r)
        ans = ans * i % mod;
        ans = ans * inv(i-r) % mod;
    }
    return ans;
}

ll nCr_loop2(ll n , ll r) { // r <= 2e6
    ll ans = 1;
    for (ll i = 1; i <= r ; ++i) { // n * n-1 .... * n-r+1
        ans = ans * (n - i + 1) % mod;
        ans = ans * inv(i) % mod;
    }
    return ans;
}

ll nPr_loop(ll n , ll r) { // r <= 2e6
    ll ans = 1;
    for (ll i = n; i >= n-r+1 ; --i) { // n * n-1 * n-2 .... n-r+1
        ans = ans * i % mod;
    }
    return ans;
}