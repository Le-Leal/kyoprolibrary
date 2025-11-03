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

int vec_contain(vector<ll> &a,ll val) {
    rep(i,a.size()) if(a[i]==val) return 1;
    return 0;
}


int main() {
    ll n,a,b; cin>>n>>a>>b;
    string s; cin>>s;
    ll ans=0;
    vl prefa(n+1),prefb(n+1); //i mozime (1-index)made
    srep(i,1,n) {
        prefa[i]=prefa[i-1]+(s[i-1]=='a');
        prefb[i]=prefb[i-1]+(s[i-1]=='b');
    }
    //vout(prefa); cout<<nl; vout(prefb); cout<<nl;
    srep(i,1,n) {
        ll lef=i-1,rig=n+1;
        while(rig-lef>1) {
            ll mid=(rig+lef)/2;
            if(prefa[mid]-prefa[i-1]>=a) rig=mid;
            else lef=mid;
        }
        ll validleft=rig;
        lef=i-1,rig=n+1;
        while(rig-lef>1) {
            ll mid=(rig+lef)/2;
            if(prefb[mid]-prefb[i-1]<b) lef=mid;
            else rig=mid;
        }
        ll validright=lef;
        if(validleft<=validright) ans+=(validright-validleft+1);
        //cout<<"i=="<<i<<" "<<validleft<<" "<<validright<<nl;
    }
    cout<<ans<<nl;
}