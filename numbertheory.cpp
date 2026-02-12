#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define print(x) for(auto i : x)cout<<i<<" ";cout<<nl
#define take(x) for(auto &i : x)cin>>i
#define all(x) x.begin(), x.end()
constexpr char nl = '\n';
constexpr int mod = 1000000007;

const int N = 1e7;

// O(nlog(log(n)))
bitset<N+1> isp;
vector<int> primes;
void sieve() {
    isp.set() , isp[0] = isp[1] = false;
    for (ll i = 4; i <= N; i += 2)
        isp[i] = false;
    for (ll p = 3; p * p <= N; p += 2) {
        if (!isp[p])continue;
        for (ll j = p * p; j <= N; j += p)
            isp[j] = false;
    }
    primes.push_back(2);
    for (int i = 3; i <= N; i+=2) {
        if (isp[i])primes.push_back(i);
    }
}



// O(nlog(log(n)))
vector<int> spf(N+1);//smallest prime factor for factor3;
void sieveSmallestPrimeFactor() {
    for (int i = 2; i <= N; i += 2)
        spf[i] = 2;
    for (int p = 3; p <= N; p += 2) { // cannot be i * i; !!
        if (spf[p])continue;
        for (int j = p; j <= N; j += p) // must start from i; !!
          if (!spf[j])spf[j] = p;
    }
}



// O(nlog(log(n)))
vector<int> distPrimes(N+1);
void sieveNoOfDistPrimeFactors(int N) {
    distPrimes[0] = distPrimes[1] = 0;
    for (int i = 2; i <= N; i += 2)
        distPrimes[i]++;
    for (int p = 3; p <= N; p += 2) {
        if (distPrimes[p] != 0)continue;
        for (int j = p; j <= N; j += p)
            distPrimes[j]++;
    }
}



// O(sqrt(n))
vector<pair<int,int>> factor(int n) {
    vector<pair<int,int>> res;
    for (ll i = 2; i * i <= n; i++) {
        int e = 0;
        while (n % i == 0) {
            e++;
            n /= i;
        }
        if (e > 0)
            res.emplace_back((int) i, e);
    }
    if (n != 1)
        res.emplace_back(n, 1);
    return res;
}

// O(sqrt(n)/log(n))
// requires sieve precomputation before running
vector<pair<int,int>> factor2(int n) {
    vector<pair<int,int>> res;
    for (int p : primes) {
        int e = 0;
        while (n % p == 0) {
            n /= p;
            e++;
        }
        if (e > 0)
            res.emplace_back(p, e);
    }
    if (n != 1)
        res.emplace_back(n, 1);
    return res;
}

// O(log(n))
// requires sieveSmallestPrimeFactor precomputation before running
vector<pair<int,int>> factor3(int n) {
    vector<pair<int,int>> res;
    while (n != 1) {
        int p = spf[n];
        int e = 0;
        while (p == spf[n]) {
            e++;
            n /= p;
        }
        res.emplace_back(p, e);
    }
    return res;
}


// divisors O(NlogN)
vector<vector<int>> Div(N);
void factors() {
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j+=i) {
            Div[j].push_back(i);
        }
    }
}



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
