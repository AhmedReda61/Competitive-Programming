#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node {
    map<char , int> mp;
    int c = 0;
    int &operator[](char ch) {
        return mp[ch];
    }
};

struct Trie {
    vector<node> tree;

    int add() {
        tree.emplace_back();
        return (int)tree.size() - 1;
    }
    Trie() {
        tree.clear();
        add();
    }

    void insert(string& s) {
        int u = 0;
        for (char c : s) {
            if (!tree[u][c])tree[u][c] = add();
            u = tree[u][c];
            tree[u].c++;
        }
    }

    int prefix_count(string& s) {
        int u = 0;
        for (char c : s) {
            if (!tree[u][c])return 0;
            u = tree[u][c];
        }
        return tree[u].c;
    }

};