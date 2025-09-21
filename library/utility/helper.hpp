#pragma once
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
using ll = long long;
#define MOD 998244353ll
#define INF 9223300000000000000ll



ll vecmax(vector<ll> &a) {
    ll ans=-INF;
    rep(i,(ll)a.size()) {
        ans=max(ans,a[i]);
    }
    return ans;
}

ll vecmin(vector<ll> &a) {
    ll ans=INF;
    rep(i,(ll)a.size()) {
        ans=min(ans,a[i]);
    }
    return ans;
}



template <class T> void vecpr(T first,T last) {
    ll tmp=0;
    for(auto it=first;it!=last;++it) {
        if(tmp) cout<<" ";
        cout<<*it;
        tmp++;
    }
    cout<<endl;
}


ll modpow(ll fl, ll po, ll mode) {  // mode: 0=modなし, 1=modあり
    ll ret=1;
    if (mode) {
        while (po>0) {
            if (po&1) ret=(ret*fl)%MOD;
            fl=(fl*fl)%MOD;
            po>>=1;
        }
    } else {
        while (po>0) {
            if(po&1) ret*=fl;
            fl*=fl;
            po>>=1;
        }
    }
    return ret;
}

ll gcd(ll a,ll b) {  //Euclid
    if(a<b) return gcd(b,a);
    if(a%b==0) return b;
    return gcd(b,a%b);
}