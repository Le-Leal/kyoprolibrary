#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> vector<T> modpow_fps(vector<T> a,ll po,ll shrink) {
    assert(po>=0 && shrink>=0);
    vector<T> ret={1};
    auto trim=[&](const vector<T>& v)->vector<T> {
        if (v.size()<=shrink+1) return v;
        return vector<T>(v.begin(),v.begin()+shrink+1);
    };
    a=trim(a);
    while(po>0) {
        if(po&1) ret=atcoder::convolution(ret,a);
        a=atcoder::convolution(a,a);
        ret=trim(ret);
        a=trim(a);
        po>>=1;
    }
    return ret;
}