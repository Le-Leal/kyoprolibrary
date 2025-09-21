#pragma once
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
using ll = long long;

vector<ll> slmax(vector<ll> a, ll limit, ll breadth) {//slidewindowによる幅breadthでの区間最大値評価,limit=a.size()
    assert(limit==a.size());
    deque<ll> deq;
    vector<ll> max_numbers(limit, (-1)*INF);
    rep(i, limit) {
        while (!deq.empty() && deq.front() <= i - breadth) deq.pop_front();
        while (!deq.empty() && a[deq.back()] <= a[i]) deq.pop_back();
        deq.push_back(i);
        max_numbers[i] = a[deq.front()];
    }
    return max_numbers;
}

vector<ll> slmin(vector<ll> a, ll limit, ll breadth) {//slidewindowによる幅breadthでの区間最小値評価,limit=a.size()
    assert(limit==a.size());
    deque<ll> deq;
    vector<ll> min_numbers(limit, INF);
    rep(i, limit) {
        while (!deq.empty() && deq.front() <= i - breadth) deq.pop_front();
        while (!deq.empty() && a[deq.back()] >= a[i]) deq.pop_back();
        deq.push_back(i);
        min_numbers[i] = a[deq.front()];
    }
    return min_numbers;
}