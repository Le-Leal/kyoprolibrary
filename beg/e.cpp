#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define srep(i,l,r) for(ll i=l;i<=r;i++)
#define irep(i,r,l) for(ll i=r;i>=l;i--)
using ll = long long;
using ld = long double;
const ll mod=998244353;
#define vout(v) for(auto i :v) cout<<i<<" "; cout<<"\n";
#define INF 9223300000000000000ll
#define Winf 5e12
#define nl "\n"
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define vl vector<ll>
#define pb push_back
#define vc vector<char>
#define vb vector<bool>
#define uniq(x) sort((x).begin(),(x).end());(x).erase(unique((x).begin(),(x).end()),(x).end())
#define eb emplace_back



void no(void) { cout<<"No"<<nl;}
void yes(void) {cout<<"Yes"<<nl;}
void yn(bool a) {
    cout<<(a ? "Yes":"No")<<nl;
}


vector<ll> dx={-1,0,1,0,1,1,-1,-1};
vector<ll> dy={0,-1,0,1,-1,1,-1,1};

bool isin(ll i,ll j,ll h,ll w) {
    if(i<0 || i>=h || j<0 || j>=w) return false;
    return true;
}

template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}


template<class T>T vecmax(const vector<T>&v){return *max_element(all(v));}
template<class T>T vecmin(const vector<T>&v){return *min_element(all(v));}

ll safemod(ll num,ll rule) {
    return (num%rule+rule)%rule;
}

ll sum(vector<ll> &a) {
    return accumulate(all(a),0ll);
}
template<class T>void vvpr(vector<vector<T>> g) {
    rep(i,g.size()) {
        rep(j,g[i].size()) {
            cout<<g[i][j]<<(j==g[i].size()-1 ? "\n":" ");
        }
    }
}

#pragma once
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
using ll = long long;

struct UnionFind {
    vector<int> par;
    vector<int> siz;
    int count;
    UnionFind(int N):par(N),siz(N,1),count(N){
        rep(i,N) par[i]=i;
    }
    int root(int x){
        return par[x]==x?x:par[x]=root(par[x]);
    }
    void unite(int x,int y){
        int rx=root(x),ry=root(y);
        if(rx==ry) return;
        count--;
        if(rx<ry) {
            par[rx]=ry;
            siz[ry]+=siz[rx];
            siz[rx]=0;
        }
        else {
            par[ry]=rx;
            siz[rx]+=siz[ry];
            siz[ry]=0;
        }
    }
    bool same(int x,int y){
        return root(x)==root(y);
    }
    int comp_count() const{
        return count;
    }
    int size(int x) {
        return siz[root(x)];
    }
};

//ファイル読み込みは第二フォルダから ex:include "mathtype/hoge.hpp"
ll enc(ll x,ll y) {
    return x*2000000000ll+y;
}
int main() {
    ll n; cin>>n;
    vl x(n),y(n);
    rep(i,n) cin>>x[i]>>y[i];
    map<ll,vector<ll>> g;
    vector<ll> par(n+1);
    rep(i,n) par[i+1]=i+1;
    rep(i,n) {
        if(!g.count(enc(x[i],y[i]))) {
            g[enc(x[i],y[i])]={i+1};
            par[i+1]=g[enc(x[i],y[i])][0];

        }
    }
    
}