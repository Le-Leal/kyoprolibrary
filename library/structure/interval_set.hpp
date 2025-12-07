#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


class intervalset {
    ll max;
    set<pair<ll,ll>> itv;
    intervalset(ll n):max(n) {}
    ll add(ll lef,ll rig) { //増えた数を返す
        auto it=itv.lower_bound({lef,rig});
        it--;
        ll apply=0;
        ll lost=0;
        if(it->first<=lef && lef<=it->second) {
            if(lef>it->first) lef=it->first;
            if(rig<it->second) rig=it->second;
            lost+=(it->second-it->first);
            itv.erase(it);
        }
        it=itv.lower_bound({lef,rig});
        while(1) {
            if(it->first<=lef && it->first<=rig) {
                if(lef>it->first) lef=it->first;
                if(rig<it->second) rig=it->second;
                lost+=(it->second-it->first);
                it=itv.erase(it);
            }
        }
        apply+=(rig-lef);
        return apply-lost;
    }
    set<pair<ll,ll>> all() {
        return itv;
    }
};