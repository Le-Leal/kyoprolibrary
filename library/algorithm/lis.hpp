#pragma once
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define srep(i,l,r) for(ll i=l;i<=r;i++)
using ll = long long;

vector<ll> lis_size(vector<ll>& a) { // 最長増加部分列の a index目までみたのがdp[a];
    ll n=a.size();
    vector<ll> dp(n,1);  
    vector<ll> seq;       

   rep(i,n) {
        auto it=lower_bound(seq.begin(), seq.end(), a[i]);
        
        if (it==seq.end())  seq.push_back(a[i]);
        else *it=a[i];
        dp[i]=distance(seq.begin(), lower_bound(seq.begin(), seq.end(), a[i]))+1;
    }
    srep(i,1,n-1) {
        if(dp[i]<dp[i-1]) dp[i]=dp[i-1]; //ここをなくすと、"a[i]を末尾とするどうちゃら"になる
    }
    return dp;
}
