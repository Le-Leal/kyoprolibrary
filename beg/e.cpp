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
#define vout(v) for(auto i :v) cout<<i<<" ";
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
//ファイル読み込みは第二フォルダから ex:include "mathtype/hoge.hpp"
struct str {
    ll origin;
    ll idx;
    ll dist;
};

int main() {
    ll n,m; cin>>n>>m;
    vector<vl> g(n);
    rep(i,m) {
        ll u,v; cin>>u>>v;
        g[--u].pb(--v);
        g[v].pb(u);
    }
    string s; cin>>s;
    vector<vl> dist(n,vl(2,-1)); //Sからの最短距離と
    vector<vl> midx(n,vl(2,-1)); //そうしてくれるS
    queue<str> que;
    rep(i,n) if(s[i]=='S') {
        que.push({i,i,0});
        dist[i][0]=0;
        midx[i][0]=i;
    }
    while(!que.empty()) {
        auto [origin,id,dis]=que.front();
        que.pop();
        ll size=g[id].size();
        auto &v=g[id];
        rep(t,size) {
            if(midx[v[t]][0]==-1) {
                dist[v[t]][0]=dis+1;
                midx[v[t]][0]=origin;
                que.push({origin,v[t],dis+1});
            }
            else if(midx[v[t]][0]!=origin && midx[v[t]][1]==-1) {
                dist[v[t]][1]=dis+1;
                midx[v[t]][1]=origin;
                que.push({origin,v[t],dis+1});
            }
        }
    }
    vl res;
    rep(i,n) if(s[i]=='D') res.pb(dist[i][0]+dist[i][1]);
    for(ll e:res) cout<<e<<nl;
}