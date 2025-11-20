#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<n;i++)

template<class T> class fastms {
    public:
        set<T> st;
        unordered_map<T,ll> cnt;
        void insert(T x) {
            if(!cnt.count(x)) st.insert(x);
            else if(cnt[x]==0) st.insert(x);
            cnt[x]++;
        }
        void erase(T x) {
            assert(cnt[x]>=1);
            if(cnt[x]==1) st.erase(x);
            cnt[x]--;
        }
        ll count(T x) {
            if(!cnt.count(x)) return 0ll;
            else return cnt[x];
        }
        ll lower_bound(ll x) {
            return distance(st.begin(),st.lower_bound(x));
        }
        ll upper_bound(ll x) {
            return distance(st.begin(),st.upper_bound(x));
        }
};