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
using lint = __int128_t;
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
//ファイル読み込みは第二フォルダから ex:include "mathtype/hoge.hpp;
ll modpow(ll fl, ll po, ll mode) {  // mode: 0=modなし, 1=modあり
    lint ret=1;
    if (mode) {
        while (po>0) {
            if (po&1) ret=(ret*fl)%mod;
            fl=(fl*fl)%mod;
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
    ll n; cin>>n;
    vl x(n+1,0);
    srep(i,1,n) cin>>x[i];
    set<pair<ll,ll>> cur;//za/idx
    vector<ll> d(n+1,2000000000ll);
    ll dsum=2000000000ll;
    cur.insert({0,0});
    vl ans(n+1);
    srep(i,1,n) {
        ll predi=INF;
        auto it=cur.lower_bound(make_pair(x[i],-1ll));
        if(it!=cur.end()) {
            //cout<<"11reached here in i=="<<i<<nl;
            auto it2=it;
            if(d[it2->second]>llabs(x[it2->second]-x[i])) {
                dsum-=(d[it2->second]-llabs(x[it2->second]-x[i]));
                chmin(d[it2->second],llabs(x[it2->second]-x[i]));
            }
            chmin(predi,llabs(x[it2->second]-x[i]));
        }
        if(it!=cur.begin()) {
            auto it2=it;
            it2--;
            //cout<<"22reached here in i=="<<i<<nl;
            if(d[it2->second]>llabs(x[it2->second]-x[i])) {
                dsum-=(d[it2->second]-abs(x[it2->second]-x[i]));
                chmin(d[it2->second],llabs(x[it2->second]-x[i]));
            }
            chmin(predi,llabs(x[it2->second]-x[i]));

        }
        //assert(predi!=INF);
        dsum+=predi;
        d[i]=predi;
        ans[i]=dsum;
        cur.insert({x[i],i});
    }
    srep(i,1,n) cout<<ans[i]<<nl;
}