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

int main() {
    ll n; cin>>n;
    vl x(n),y(n);
    rep(i,n) cin>>x[i]>>y[i];
    ll xr=vecmax(x)-vecmin(x);
    ll yr=vecmax(y)-vecmin(y);
    ll blk=(ll)sqrtl(xr*yr/n);
    if(blk==0) blk=1;
    vl iot(n);
    ll mx=vecmin(x);
    rep(i,n) iot[i]=i;
    sort(all(iot),[&](ll a,ll b) {
        if((x[a]-mx)/blk==(x[b]-mx)/blk) {
            if(!(((x[a]-mx)/blk)%2)) {
                if(y[a]==y[b]) return a<b;
                return y[a]<y[b];
            }
            else {
                if(y[a]==y[b]) return a<b;
                return y[a]>y[b];
            }
        }
        return (x[a]-mx)/blk<(x[b]-mx)/blk;
    });
    ll z=-1;
    rep(i,n) {
        if(iot[i]==0) z=i;
    }
    vl ans;
    srep(i,z,n-1) {
       ans.pb((iot[i])+1); 
    }
    rep(i,z) {
        ans.pb((iot[i])+1);
    }
    vout(ans);
}