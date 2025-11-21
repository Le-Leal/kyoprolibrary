#pragma once
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
using ll = long long;
#define vl vector<ll>

vector<vl> matmul(vector<vl> a,vector<vl> b,ll _MOD_,bool mode) {
    assert(a.size()>0 && b.size()>0);
    assert(a[0].size()==b.size());
    vector<vl> res(a.size(),vl(b[0].size(),0));
    rep(i,a.size()) {
        rep(j,b[0].size()) {
            rep(k,b.size()) {
                res[i][j]+=a[i][k]*b[k][j];
                if(mode) res[i][j]%=_MOD_;
            }
        }
    }
    return res;
}

vector<vl> matpow_by_mod(vector<vl> a,ll po,ll _MOD_) {
    ll n=a.size();
    vector<vl> res(n,vl(n));
    rep(i,n) res[i][i]=1;
    while(po>0) {
        if(po&1) {
            res=matmul(res,a,_MOD_,true);
        }
        a=matmul(a,a,_MOD_,true);
        po>>=1;
    }
    return res;

}
