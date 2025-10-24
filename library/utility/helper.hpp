//数学系多めのヘルパー
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
    fl%=MOD;
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

ll modpow2(ll fl,ll po,ll modulo) { //ninni mod
    ll ret=1;
    fl%=modulo;
    while (po>0) {
        if (po&1) ret=(ret*fl)%modulo;
        fl=(fl*fl)%modulo;
        po>>=1;
    }
    return ret;
}

ll modpowlarge(ll fl,string po,ll modulo) { // po がクソでかい用
    if (modulo==1) return 0;
    fl%=modulo;
    ll res=1%modulo;
    for (char c:po) {
        ll d=c-'0';
        res=modpow2(res, 10, modulo);
        if(d) res=(res*modpow2(fl,d,modulo))%modulo;
    }
    return res;
}

vector<ll> pfact(ll n) {
    vector<ll> resp;
    vector<bool> prefact(sqrtl(n)+10);
    for(ll i=2;i*i<=n;i++) {
        while(n%i==0) {
            n/=i;
            if(!prefact[i]) resp.push_back(i);
            prefact[i]=true;
        }
    }
    if(n!=1) resp.push_back(n);
    return resp;
}


ll modinv(ll a, ll mod) { //拡張Euclidによるmodでの逆元, a*u+mod*v=1を解く
	ll b=mod,u=1,v=0;
	while (b) {
		ll t=a/b;
		a-=t*b;
        swap(a,b);
		u-=t*v;
        swap(u,v);
	}
	u%=mod; 
	if (u < 0) u+=mod;
	return u;
}

ll extgcd(ll a, ll b, ll &x, ll &y) { // ax+by=gcd(a,b) -> x,yを格納
    if (b==0) {
        x=1;
        y=0;
        return a;
    }
    ll d=extgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

ll divcount(ll n) {
    ll ans=0;
    for(int i=1;i*i<=n;i++) {
        if(n%i==0) ans+=(i*i==n ? 1:2);
    }
    return ans;
