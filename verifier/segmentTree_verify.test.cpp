#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <bits/stdc++.h>
#include "../library/structure/segmentTree.hpp"
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)

int main() {
    int n,q; cin >> n >> q;
    function<ll(ll,ll)> op=[](ll a,ll b) { return a+b;};
    function<ll()> e=[]() { return 0ll;};
    segtree<ll> seg(n,op,e);
    rep(i,n) {
        ll x; cin>>x;
        seg.set(i,x);
    }
    rep(i,q) {
        ll ty; cin>>ty;
        if(ty==0) {
            ll p,x; cin>>p>>x;
            seg.add(p,x);
        } else if(ty==1) {
            ll l,r; cin>>l>>r;
            cout<<seg.prod(l,r)<<endl;
        }
    }
}