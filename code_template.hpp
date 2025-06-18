#ifndef INCLUDED_MAIN
#define INCLUDED_MAIN

#include __FILE__

int main(){
    ll n;
    cin>>n;
    vector<vector<char>> f1(n,vector<char>(n)),f2(n,vector<char>(n));
    rep(i,n) rep(j,n) cin>>f1[i][j];
    rep(i,n) rep(j,n) cin>>f2[i][j];
    ll ans=INF;
    rep(ii,4) {
        ll cur=ii;
        rep(i,n) rep(j,n) {
            if(f1[i][j]!=f2[i][j]) cur++;
        }
        ans=min(ans,cur);
        f1=rotate(f1,n);
    }
    cout<<ans<<nl;
}

/////// library zone ///////
#else
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define srep(i,l,r) for(ll i=l;i<=r;i++)
using ll = long long;
using ld = long double;
const ll mod=998244353;
#define vout(v) for(auto i :v) cout<<i<<" ";
#define INF 9223300000000000000ll
#define Winf 5e12
#define nl "\n"
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define vl vector<ll>
#endif