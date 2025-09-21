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

template<class T>void vvpr(vector<vector<T>> g) {
    rep(i,g.size()) {
        rep(j,g[i].size()) {
            cout<<g[i][j]<<(j==g[i].size()-1 ? "\n":" ");
        }
    }
}


ll sum(vector<ll> &a) {
    return accumulate(all(a),0ll);
}
//ファイル読み込みは第二フォルダから ex:include "mathtype/hoge.hpp"
int main() {
    ll t; cin>>t;
    vector<ll> anss(t);
    rep(tt,t) {
        ll h,w; cin>>h>>w;
        vector<vc> g(h,vc(w));
        rep(i,h) rep(j,w) cin>>g[i][j];
        function<bool(ll,ll)> inval=[&](ll i,ll j)->bool {
            return (g[i][j]==g[i+1][j] && g[i+1][j]==g[i][j+1] && g[i][j+1]==g[i+1][j+1] && g[i][j]=='#');
        };
        function<ll(ll,ll)> countinv=[&](ll i,ll j)->ll {
            ll ans=0;
            rep(ii,2) {
                rep(jj,2) {
                    if(i-ii>=0 && j-jj>=0 && i-ii+1<h && j-jj+1<w) {
                        if(g[i-ii][j-jj]==g[i+1-ii][j-jj] && g[i+1-ii][j-jj]==g[i-ii][j+1-jj] && g[i-ii][j+1-jj]==g[i+1-ii][j+1-jj] && g[i-ii][j-jj]=='#')ans++;

                    }
                }
            }
            return ans;
        };
        ll res=0;
        rep(i,h-1) {
            rep(j,w-1) {
                if(inval(i,j)) {
                    vector<ll> p(4);
                    rep(k,4) p[k]=countinv(i+(k/2),j+(k%2));
                    ll ind=-1,val=-1;
                    rep(k,4) if(chmax(val,p[k])) {
                        ind=k;
                    }
                    g[i+ind/2][j+ind%2]='.';
                    res++;
                    //vvpr(g);
                    //cout<<nl;
                }
            }
        }
        anss[tt]=res;
    }
    rep(i,t) cout<<anss[i]<<nl;
}