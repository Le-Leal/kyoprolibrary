#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct dictional_uf {
    public:
        unordered_map<ll,ll> par;
        unordered_map<ll,ll> rank;
        dictional_uf():par(),rank(){}
        void add(ll key) {
            par[key]=key;
            rank[key]=1;
        }
        ll find(ll x) {
            if(x==par[x]) return x;
            else return par[x]=find(par[x]);
        }
        bool unite(ll x,ll y) {
            ll px=find(x),py=find(y);
            if(px==py) return false;
            if(px<py) {
                par[px]=py;
                rank[py]+=rank[px];
                rank[px]=0;
            }
            else {
                par[py]=px;
                rank[px]=rank[py];
                rank[py]=0;
            }
            return true;
        }
        
};
