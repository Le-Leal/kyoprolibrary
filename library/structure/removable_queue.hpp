#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T, class comp=less<T>> class removable_queue {
    public:
        ll count=0,sum=0;
        void push(const T &x) {
            que.push(x);
            count++;
            sum+=x;
            balance();
        }
        void pop() {
            assert(!que.empty());
            balance();
            T v=que.top();
            que.pop();
            --count;
            sum-=(ll)v;
            balance();
        }
        void erase(const T &x) {
            del.push(x);
            --count;
            sum-=(ll)x;
            balance();
        }
        const T& top() {
            assert(!que.empty());
            balance();
            return que.top();
        }
        bool empty() {
            return count==0;
        }
        ll size() {
            return (ll)count;
        }
    private:
        priority_queue<T,vector<T>,comp> que,del;
        void balance() {
            while (!del.empty() && !que.empty() && que.top()==del.top()) {
                que.pop();
                del.pop();
            }
        }
};
