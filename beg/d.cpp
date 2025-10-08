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
    return accumulate(all(a),0);
}
template<class T>void vvpr(vector<vector<T>> g) {
    rep(i,g.size()) {
        rep(j,g[i].size()) {
            cout<<g[i][j]<<(j==g[i].size()-1 ? "\n":" ");
        }
    }
}
//ファイル読み込みは第二フォルダから ex:include "mathtype/hoge.hpp;

int main() {
    ll h,w,k; cin>>h>>w>>k;
    vector<vector<char>> g(h,vc(w));
    rep(i,h) rep(j,w) cin>>g[i][j];
    ll ans=0;
    vector<vector<bool>> used(h,vector<bool>(w,false));
    function<void(ll,ll,ll)> dfs=[&](ll turn,ll i,ll j)->void {
        if(turn==k) {
            ans++;
            return;
        }
        rep(q,4) {
            ll nx=i+dx[q],ny=j+dy[q];
            if(!isin(nx,ny,h,w)) continue;
            if(used[nx][ny]) continue;
            if(g[nx][ny]=='#') continue;
            used[nx][ny]=true;
            dfs(turn+1,nx,ny);
            used[nx][ny]=false;
        }
    };
    rep(ii,h) rep(jj,w) {
        if(g[ii][jj]=='#') continue;
        used[ii][jj]=1;
        dfs(0,ii,jj);
        used[ii][jj]=0;
    }
    cout<<ans<<nl;
}