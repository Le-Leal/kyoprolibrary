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
    vector<ll> diags;
    string str;
    ll q; cin>>q;
    ll minusc=0;
    rep(i,q) {
        ll ty; cin>>ty;
        if(ty==1) {
            char c; cin>>c;
            str.pb(c);
            ll add;
            if(c=='(') add=1; else add=-1;
            if(diags.size()==0) diags.pb(add);
            else diags.pb(diags[diags.size()-1]+add);
            if(diags.back()<0) minusc++;
        }
        else {
            str.pop_back();
            if(diags[diags.size()-1]<0) minusc--;
            diags.pop_back();
        }
        bool b=false;
        if(diags.size()==0) b=true;
        else if(diags.back()==0) b=true;
        yn(b && minusc==0);
        //vout(diags) cout<<str<<" "<<minusc<<nl;
    }
}