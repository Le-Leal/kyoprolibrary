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
#define vout(v) for(auto i :v) cout<<i<<" ";  cout<<nl;
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
class factset {
    public:
        vl _fact;
        vl _inv;
        ll __n;
        factset(ll n):_fact(n+1),_inv(n+1),__n(n) {
            _fact[0]=1;
            srep(i,1,__n) {
                _fact[i]=_fact[i-1]*i;
                _fact[i]%=MOD;
            }
            _inv[__n]=modpow(_fact[__n],MOD-2,1);
            for(int i=__n-1;i>=0;i--) {
                _inv[i]=_inv[i+1]*(i+1);
                _inv[i]%=MOD;
            }
        }
        ll fact(ll x) {
            assert(0<=x && x<=__n);
            return _fact[x];
        }
        ll inv(ll x) {
            assert(0<=x && x<=__n);
            return _inv[x];
        }

        ll comb(ll nn,ll k) {
            if(nn<k) return 0;
            ll ans=1;
            ans*=_fact[nn];
            ans%=MOD;
            ans*=_inv[nn-k];
            ans%=MOD;
            ans*=_inv[k];
            return ans%MOD;
        }
        
};
struct stone {
    ll x,y,c;
};
int main() {
    ll n,m; cin>>n>>m;
    vector<stone> stn(m-1);
    ll rs,re;
    vector<vector<pair<ll,ll>>> g(2*n);
    ll prec;
    rep(i,m) {
        ll x,y,c; cin>>x>>y>>c;
        x--; y--;
        if(i==0) {
            if(x==y) {
                cout<<c<<nl;
                return 0;
            }
            rs=x;
            re=y+n;
            prec=c;
        }
        else {
            if(x==y) continue;
            g[y+n].pb({x,c});
        }
    }
    rep(i,n) g[i].pb({i+n,0});
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,rs});
    vl dist(2*n,INF);
    dist[rs]=0;
    while(!pq.empty()) {
        auto [dis,v]=pq.top();
        pq.pop();
        if(dis>dist[v]) continue;
        for(auto [nx,cost]:g[v]) {
            ll nd=dis+cost;
            if(nd>=dist[nx]) continue;
            dist[nx]=nd;
            pq.push({nd,nx});
        }
    }
    //vout(dist);
    if(dist[re]==INF) cout<<-1<<nl;
    else cout<<dist[re]+prec<<nl;
    return 0;
}