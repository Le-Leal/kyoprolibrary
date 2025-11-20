#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T, class comp=less<T>> class removable_queue {
    public:
        void push(const T &x) {
            que.push(x);
            balance();
        }
        void pop() {
            assert(!que.empty());
            balance();
            que.pop();
            balance();
        }
        void erase(const T &x) {
            del.push(x);
            balance();
        }
        const T& top() {
            assert(!que.empty());
            balance();
            return que.top();
        }
        bool empty() {
            balance();
            return que.empty();
        }
        ll size() {
            if((int)que.size()-(int)del.size()<0) assert(false);
            return que.size()-del.size();
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
