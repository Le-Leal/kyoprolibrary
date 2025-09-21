#pragma once
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define srep(i,l,r) for(ll i=l;i<=r;i++)
#define irep(i,r,l) for(ll i=r;i>=l;i--)
using ll = long long;
using ld = long double;
#include "mathHelper.hpp"

bool crt(ll a1,ll m1,ll a2,ll m2,ll &r,ll &lcm) {
    ll x,y;
    ll g=extgcd(m1,m2,x,y);
    if ((a2-a1)%g!=0) return false; // No sols.

    ll _MOD_=m1/g*m2;
    ll tmp=((a2-a1)/g*x)%(m2/g);
    r=(a1+m1*tmp)%_MOD_;
    if (r<0) r+=_MOD_;
    lcm=_MOD_;
    return true;
}