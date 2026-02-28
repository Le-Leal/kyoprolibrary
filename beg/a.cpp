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
#define vout(v) for(auto i :v) cout<<i<<" "; cout<<nl;
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
#define MOD 998244353
template<class T> T modpow(T fl, ll po, ll mode) {  // mode: 0=modなし, 1=modあり
    assert(po>=0);
    T ret(1);
    if (mode) {
        fl%=T(MOD);
        while (po>0) {
            if (po&1) ret=(ret*fl)%T(MOD);
            fl=(fl*fl)%T(MOD);
            po>>=1;
        }
    } else {
        while (po>0) {
            if(po&1) ret*=fl;
            fl*=fl;
            po>>=1;
        }
    }
    return ret;
}

int main() {
    ll q; cin>>q;
    rep(tt,q) {
        ll n; cin>>n;
        vector<vl> g(n);
        vl deg(n);
        rep(i,n-1) {
            ll a,b; cin>>a>>b;
            g[--a].pb(--b);
            g[b].pb(a);
            deg[a]++;
            deg[b]++;
        }
        ll sugata=0;
        vl dpopen(n,0),dpclose(n,0);
        vl par(n,-1);
        function<void(ll)> dfs=[&](ll v)->void {
            for(auto nx:g[v]) {
                if(nx==par[v]) continue;
                par[nx]=v;
                dfs(nx);
            }
        };
        dfs(0);
        function<void(ll)> f=[&](ll v)->void {
            if(deg[v]>=2) {
                if(deg[v]>=3) dpopen[v]=1;
                dpclose[v]=1;
            }
            ll ma=0,ma2=0;
            for(auto cld:g[v]) {
                if(cld==par[v]) continue;
                f(cld);
                if(deg[v]>=3) chmax(dpclose[v],dpopen[cld]+1);
                if(deg[v]>=4) {
                    chmax(dpopen[v],dpopen[cld]+1);
                    if(ma<=dpopen[cld]) {
                        ma2=ma;
                        ma=dpopen[cld];
                    }
                    else if(ma2<dpopen[cld]) {
                        ma2=dpopen[cld];
                    }
                }
                chmax(dpclose[v],ma+ma2+1);
                
            }

        };
        f(0);
        //vout(dpclose); vout(dpopen);
        cout<<max(*max_element(all(dpclose)),*max_element(all(dpopen)))<<nl;
    }
}