#pragma once
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
using ll = long long;

template<class T>
struct ValueHavinguf {
    vector<int> par;
    vector<int> siz;
    vector<T> info;   // 各成分の値
    vector<T> node;   // 各ノードの値
    function<T(const T&, const T&)> op;
    int count;

    ValueHavinguf(ll n, function<T(const T&, const T&)> op_, const T& def=T())
        : par(n),siz(n,1),info(n),node(n, def),op(move(op_)),count(n) {
        rep(i,n) {
            par[i]=i;
            info[i]=def;
        }
    }

    ValueHavinguf(const vector<T>& initial, function<T(const T&, const T&)> op_)
        : par((ll)initial.size()), siz(initial.size(), 1),
          info(initial), node(initial),
          op(move(op_)), count((int)initial.size()) {
        rep(i,(ll)par.size()) par[i]=i;
    }

    int root(int x){
        if(par[x]==x) return x;
        else return par[x]=root(par[x]);
    }

    void unite(int x,int y){
        int rx=root(x), ry=root(y);
        if (rx==ry) return;
        if (siz[rx]<siz[ry]) {
            par[rx]=ry;
            siz[ry]+=siz[rx];
            siz[rx]=0;
            info[ry]=op(info[rx],info[ry]);
            info[rx]=T();
        } else {
            par[ry]=rx;
            siz[rx]+=siz[ry];
            siz[ry]=0;
            info[rx]=op(info[rx],info[ry]);
            info[ry]=T();
        }
        --count;
    }

    bool same(int x,int y) {
        return root(x)==root(y);
    }

    int comp_count() {
        return count;
    }

    T& getinfo(int x) {
        return info[root(x)];
    }

    T getnode(int x) { 
        return node[x]; 
    }

    void setnode(int x,const T& v) {
        int r=root(x);
        if(op(1,1)==2) {
            info[r]=info[r]-node[x]+v;
        } 
        else {
            info[r]=(info[r]^node[x])^v;
        }
        node[x]=v;
    }

    int size(int x) {
        return siz[root(x)];
    }
};