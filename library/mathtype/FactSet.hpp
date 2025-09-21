#pragma once
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define srep(i,l,r) for(ll i=l;i<=r;i++)
#define irep(i,r,l) for(ll i=r;i>=l;i--)
using ll = long long;
using ld = long double;
#define MOD 998244353ll
#define vl vector<ll>
#include "../utility/helper.hpp"


class factset {
    public:
        vl _fact;
        vl _inv;
        ll __n;
        factset(ll n):_fact(n+1),_inv(n+1),__n(n) {
            _fact[0]=1;
            srep(i,1,__n) {
                _fact[i]=_fact[i-1]*i;
                _fact[i]%=MOD;
            }
            _inv[__n]=modpow(_fact[__n],MOD-2,1);
            for(int i=__n-1;i>=0;i--) {
                _inv[i]=_inv[i+1]*(i+1);
                _inv[i]%=MOD;
            }
        }
        ll fact(ll x) {
            assert(0<=x && x<=__n);
            return _fact[x];
        }
        ll inv(ll x) {
            assert(0<=x && x<=__n);
            return _inv[x];
        }

        ll comb(ll nn,ll k,ll mode) {
            ll ans=1;
            ans*=_fact[nn];
            ans%=MOD;
            ans*=_inv[nn-k];
            ans%=MOD;
            ans*=_inv[k];
            return ans%MOD;
        }
        
};