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
bool fastsquare(ll n) {
    ll rt=ll(sqrtl(n));
    for(ll r=rt-5;r<=rt+5;r++) {
        if(r*r==n) return true;
    }
    return false;
}

ll ketasuu(ll n) {
    ll res=0;
    while(true) {
        if(0<=n && n<=9) return res+1;
        n/=10;
        res++;
    }
}

lint modpow(lint fl, ll po, ll mode) {  // mode: 0=modなし, 1=modあり
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
    ll t; cin>>t;
    vl anss(t);
    rep(tt,t) {
        ll cc,dd; cin>>cc>>dd;
        lint c=cc,d=dd;
        ll minn=ketasuu(c+1);
        ll maxn=ketasuu(c+d);
        ll ans=0;
        for(ll n=minn;n<=maxn;n++) {
            lint lefk,rigk;
            lefk=modpow(10,n,0)*c+c+1;
            rigk=d+modpow(10,n,0)*c+c;
            chmax(lefk,modpow(10,n,0)*c+modpow(10,n-1,0));
            chmin(rigk,modpow(10,n,0)*c+modpow(10,n,0)-1);
            lint validlef,validrig;
            lint lef=-1,rig=(lint)2000000000;
            while(rig-lef>1) {
                lint mid=(lef+rig)/2;
                if(lefk<=mid*mid) rig=mid;
                else lef=mid;
            }
            validlef=rig;
            lef=-1,rig=(lint)2000000000;
            while(rig-lef>1) {
                lint mid=(lef+rig)/2;
                if(mid*mid<=rigk) lef=mid;
                else rig=mid;
            }
            validrig=lef;
            if(validlef<=validrig) ans+=(validrig-validlef+1);
        }
        anss[tt]=ans;
    }
    rep(tt,t) cout<<anss[tt]<<nl;
}