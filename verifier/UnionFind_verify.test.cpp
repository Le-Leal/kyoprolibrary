#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <bits/stdc++.h>
#include "../library/structure/UnionFind.hpp"
using namespace std;

int main() {
    int n,q; cin>>n>>q;
    UnionFind uf(n);
    while(q--) {
        int t,x,y; cin>>t>>x>>y;
        if(t==0) {
            uf.unite(x,y);
        }
        if(t==1) {
            cout<<(uf.same(x,y) ? 1 : 0)<<endl;
        }
    }
         
}