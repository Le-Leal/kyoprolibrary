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
class intervalset {
    ll max;
    set<pair<ll,ll>> itv;
    intervalset(ll n):max(n) {}
    ll add(ll lef,ll rig) { //増えた数を返す
        auto it=itv.lower_bound({lef,rig});
        it--;
        ll apply=0;
        ll lost=0;
        if(it->first<=lef && lef<=it->second) {
            if(lef>it->first) lef=it->first;
            if(rig<it->second) rig=it->second;
            lost+=(it->second-it->first);
            itv.erase(it);
        }
        it=itv.lower_bound({lef,rig});
        while(1) {
            if(it->first<=lef && it->first<=rig) {
                if(lef>it->first) lef=it->first;
                if(rig<it->second) rig=it->second;
                lost+=(it->second-it->first);
                it=itv.erase(it);
            }
        }
        apply+=(rig-lef);
        return apply-lost;
    }
    set<pair<ll,ll>> inner() {
        return itv;
    }
};

int main() {
    ll n,q; cin>>n>>q;
    vl a(n);
    rep(i,n) cin>>a[i];
    sort(all(a));
    rep(qq,q) {
        ll x,y; cin>>x>>y;
        ll lef=-1,rig=1e11;
        while(rig-lef>1) {
            ll mid=(rig+lef)/2;
            ll aa=mid-x+1;
            ll res=upper_bound(all(a),mid)-upper_bound(all(a),x-1);
            if(aa-res>=y) rig=mid;
            else lef=mid;
        }
        cout<<rig<<nl;
    }
}