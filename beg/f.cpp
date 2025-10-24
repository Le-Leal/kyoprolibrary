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
bool isnum(char c) {
    return ('0'<=c && c<='9');
}
#define MOD 998244353
ll modpow(ll fl, ll po, ll mode) {  // mode: 0=modなし, 1=modあり
    ll ret=1;
    if (mode) {
        while (po>0) {
            if (po&1) ret=(ret*fl)%MOD;
            fl=(fl*fl)%MOD;
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

ll modpow2(ll fl,ll po,ll modulo) { //ninni mod
    ll ret=1;
    fl%=modulo;
    while (po>0) {
        if (po&1) ret=(ret*fl)%modulo;
        fl=(fl*fl)%modulo;
        po>>=1;
    }
    return ret;
}

ll modpowlarge(ll fl,string po,ll modulo) { // po がクソでかい用
    if (modulo==1) return 0;
    fl%=modulo;
    ll res=1%modulo;
    for (char c:po) {
        ll d=c-'0';
        res=modpow2(res, 10, modulo);
        if(d) res=(res*modpow2(fl,d,modulo))%modulo;
    }
    return res;
}


ll modinv(ll a, ll mod) { //拡張Euclidによるmodでの逆元, a*u+mod*v=1を解く
	ll b=mod,u=1,v=0;
	while (b) {
		ll t=a/b;
		a-=t*b;
        swap(a,b);
		u-=t*v;
        swap(u,v);
	}
	u%=mod; 
	if (u < 0) u+=mod;
	return u;
}

ll extgcd(ll a, ll b, ll &x, ll &y) { // ax+by=gcd(a,b) -> x,yを格納
    if (b==0) {
        x=1;
        y=0;
        return a;
    }
    ll d=extgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}


bool crt(ll a1,ll m1,ll a2,ll m2,ll &r,ll &lcm) { //x=a1 mod m1 and x=a2 mod m2を合成してx=r mod lcmになる
    ll x,y;
    ll g=extgcd(m1,m2,x,y);
    if ((a2-a1)%g!=0) return false; // No sols.

    ll _MOD_=m1/g*m2;
    ll tmp=((a2-a1)/g*x)%(m2/g);
    r=(a1+m1*tmp)%_MOD_;
    if (r<0) r+=_MOD_;
    lcm=_MOD_;
    return true;
}

ll stollmod(string s,ll modulo) {
    ll r=0;
    for(char c:s) r=(r*10+(c-'0'))%modulo;
    return r;
}


void solve() {
    ll n,m; cin>>n>>m;
    vector<string> k(m);
    rep(i,m) cin>>k[i];
    vl ans(m);
    rep(i,m) {
        string &kc=k[i];
        ll n1=n%2,s1=0;
        if(n1==1) {
            s1=stollmod(kc,2)+1;
            s1%=2;
        }
        else {
            ll pv=modpowlarge(n1,kc,2)*n1;
            pv%=2;
            ll cld=(pv-1+2)%2;
            ll mom=(n1-1+2)%2;
            ll iv=modinv(mom,2);
            s1=(cld*iv)%2;
        }
        ll n2=n%499,s2=0;
        if(n2==1) {
            s2=stollmod(kc,499)+1;
            s2%=499;
        }
        else {
            ll pv2=modpowlarge(n2,kc,499)*n2;
            pv2%=499;
            ll cld2=(pv2-1+499)%499;
            ll mom2=(n2-1+499)%499;
            ll iv2=modinv(mom2,499);
            s2=(cld2*iv2)%499;
        }
        ll r,lcm;
        crt(s1,2,s2,499,r,lcm);
        ans[i]=(r%998+998)%998;
    }
    rep(i,m) cout<<ans[i]<<nl;
}

int main() {
    ll t; cin>>t;
    rep(tt,t) solve();
}