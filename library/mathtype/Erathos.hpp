#pragma once
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define srep(i,l,r) for(ll i=l;i<=r;i++)
using ll = long long;
using ld = long double;
#define vl vector<ll>

vector<ll> Erasieve(ll n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false; 

    for (int i=2;i*i<=n;++i) {
        if (is_prime[i]) {
            for (int j=i*i;j<=n;j+=i) is_prime[j] = false;
        }
    }
    vector<ll> primes;
    srep(i,2,n) {
        if (is_prime[i]) primes.push_back(i);
    }

    return primes;
}

vector<ll> Erasieve_segment(ll lef, ll rig) {
    ll M = floor(sqrt(rig)+100);
    vector<bool> isprime(M+1,true);
    isprime[0]=isprime[1]=false;
    for (ll p=2; p*p<=M; ++p) {
        if (!isprime[p]) continue;
        for (ll q=p*p; q<=M; q+=p) isprime[q]=false;
    }

    vector<bool> isp2(rig-lef+1,true);
    for (ll p=2; p<=M; ++p) {
        if (!isprime[p]) continue;
        ll start=max(p*p,((lef+p-1)/p)*p);
        for (ll q=start; q<=rig; q+=p)
            isp2[q-lef] = false;
    }
    vector<ll> res;

    for (ll x=max(lef,2LL) ; x<=rig ; ++x)
        if (isp2[x-lef])
            res.push_back(x);
    return res;
}



vector<vector<pair<ll,int>>> factor_range(ll L,ll R){ //lef以上rig以下のものの、素因数分解の結果を(因数、指数)で返す O(max(r-l,sqrt(r)))
    ll n=R-L+1;
    vector<ll> v(n);
    iota(v.begin(),v.end(),L);
    vector<vector<pair<ll,int>>> res(n);
    for(ll p=2; p*p<=R; ++p){
        ll s=max(p*p,(L+p-1)/p*p);
        for(ll j=s; j<=R; j+=p){
            int i=j-L, c=0;
            while(v[i] % p == 0) v[i]/=p, ++c;
            if(c) res[i].emplace_back(p,c);
        }
    }
    rep(i,n) if(v[i] > 1) res[i].emplace_back(v[i],1);
    return res;
}