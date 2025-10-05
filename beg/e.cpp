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
ll modpow(ll fl, ll po, ll mode) {  // mode: 0=modなし, 1=modあり
    ll ret=1;
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
struct point {
    ld sx,sy,gx,gy,goaltime;
};
#include <geometry/distance.hpp>
#include <atcoder/lazysegtree>
int main() {
    ll tc; cin>>tc;
    vector<ld> anss(tc);
    point ta,ao;
    rep(tt,tc) {
        rep(i,2) {
            ld sx,sy,gx,gy;
            cin>>sx>>sy>>gx>>gy;
            if(i==0) ta={sx,sy,gx,gy,0};
            else ao={sx,sy,gx,gy,0};
        }
        ta.goaltime=(ta.gy-ta.sy)*(ta.gy-ta.sy)+(ta.gx-ta.sx)*(ta.gx-ta.sx);
        ao.goaltime=(ao.gy-ao.sy)*(ao.gy-ao.sy)+(ao.gx-ao.sx)*(ao.gx-ao.sx);
        ta.goaltime=sqrtl(ta.goaltime);
        ao.goaltime=sqrtl(ao.goaltime);
        if(ta.goaltime>ao.goaltime) swap(ta,ao); //aoがうごいてtaはとまる
        ld ans=Winf;
        ld mx,my;
        ld vtx=0,vty=0,vax=0,vay=0;
        const ld Meps=1e-18;
        if (fabsl(ta.goaltime)>Meps) {
            vtx=(ta.gx-ta.sx)/ta.goaltime;
            vty=(ta.gy-ta.sy)/ta.goaltime;
        }
        if (fabsl(ao.goaltime)>Meps) {
            vax=(ao.gx-ao.sx)/ao.goaltime;
            vay=(ao.gy-ao.sy)/ao.goaltime;
        }
        ld tx_relx=ta.gx-ta.sx;
        ld tx_rely=ta.gy-ta.sy;
        ao.sx-=ta.sx;
        ao.sy-=ta.sy;
        ao.gx-=ta.sx;
        ao.gy-=ta.sy;
        ta.sx=ta.sy=ta.gx=ta.gy=0;
        mx=ao.sx+ta.goaltime*(vax-vtx);
        my=ao.sy+ta.goaltime*(vay-vty);
        chmin(ans,dist(0,0,ao.sx,ao.sy));
        chmin(ans,dist(0,0,mx,my));
        ld s2_endx=ao.gx-tx_relx;
        ld s2_endy=ao.gy-tx_rely;
        chmin(ans,dist(0,0,s2_endx,s2_endy));
        chmin(ans,dist(0,0,ao.gx,ao.gy));
        ld epsil=1e-12;
        
        anss[tt]=ans;
    }
    cout<<fixed<<setprecision(15);
    rep(i,tc) cout<<anss[i]<<nl;
}