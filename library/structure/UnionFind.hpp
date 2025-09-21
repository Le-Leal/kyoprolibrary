#pragma once
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
using ll = long long;

struct UnionFind {
    vector<int> par;
    vector<int> siz;
    int count;
    UnionFind(int N):par(N),siz(N,1),count(N){
        rep(i,N) par[i]=i;
    }
    int root(int x){
        return par[x]==x?x:par[x]=root(par[x]);
    }
    void unite(int x,int y){
        int rx=root(x),ry=root(y);
        if(rx==ry) return;
        count--;
        if(siz[rx]<siz[ry]) {
            par[rx]=ry;
            siz[ry]+=siz[rx];
            siz[rx]=0;
        }
        else {
            par[ry]=rx;
            siz[rx]+=siz[ry];
            siz[ry]=0;
        }
    }
    bool same(int x,int y){
        return root(x)==root(y);
    }
    int comp_count() const{
        return count;
    }
    int size(int x) {
        return siz[root(x)];
    }
};