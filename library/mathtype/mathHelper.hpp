#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


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
}


