#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node {
    int mp[2]{};
    int c = 0;

    int &operator[](int ch) {
        return mp[ch];
    }
};

struct BinaryTrie {
    vector<node> tree;

    int add() {
        tree.emplace_back();
        return (int)tree.size() - 1;
    }

    BinaryTrie() {
        tree.clear();
        add();
    }

    void insert(int n) {
        int u = 0;
        for (int i = 30; i >= 0 ; --i) {
            bool j = (n>>i) & 1;
            if (!tree[u][j])tree[u][j] = add();
            u = tree[u][j];
            tree[u].c++;
        }
    }

    void del(int n) {
        int u = 0;
        for (int i = 30; i >= 0 ; --i) {
            bool j = (n>>i) & 1;
            u = tree[u][j];
            tree[u].c--;
        }
    }

    int mxXor(int n) {
        int u = 0 , ret = 0;
        for (int i = 30; i >= 0 ; --i) {
            bool j = (n>>i) & 1;
            int v = tree[u][!j];
            if (v && tree[v].c) {
                ret += (1<<i);
                u = tree[u][!j];
            }else {
                u = tree[u][j];
            }
        }
        return ret;
    }

};