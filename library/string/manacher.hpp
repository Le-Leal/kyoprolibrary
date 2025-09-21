#pragma once
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(A) A.begin(),A.end()
using ll = long long;

string sp(string &s) { //manacher,丸ごとほしければradをもらう
    string t="*#";
    rep(i,(ll)s.size()) {
        t+=s[i];
        t+="#";
    }
    t+="~";
    ll n=t.size();
    vector<ll> rad(n);
    int i=0,j=0;
    while(i<n) {
        while(i-j>=0 && i+j<n && t[i-j]==t[i+j]) ++j;
        rad[i]=j;
        int k=1;
        while(i-k>=0 && k+rad[i-k]<j) rad[i+k]=rad[i-k],++k;
        i+=k; j-=k;
    }
    rep(i,n) rad[i]--;
    
    int besti;
    rep(i,n) {
        if(i+rad[i]==n-2) {
            besti=i;break;
        }
        if(i==n-1) return "owari";
    }
    string add;
    ll truerad=(rad[besti]+1)/2;
    ll truei=(besti-rad[besti]+1-2)/2;
    add=s.substr(0,truei);
    reverse(all(add));
    return s+add;
}
