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


ll m;
ll modpow(ll fl, ll po, ll mode) {  // mode: 0=modなし, 1=modあり
    ll ret=1;
    if (mode) {
        while (po>0) {
            if (po&1) ret=(ret*fl)%m;
            fl=(fl*fl)%m;
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
ld dist(ld x,ld y,ld x1,ld y1) {
    ld p=(x1-x)*(x1-x)+(y1-y)*(y1-y);
    return sqrtl(p);
}

ld line_point_dist(ld a,ld b,ld c) {
    ld fracmom=sqrtl(a*a+b*b);
    ld epsil=1e-12;
    if(fracmom<=epsil) return Winf;
    else return fabsl(c)/fracmom;
}

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
        ld la=(my-ao.sy);
        ld lb=(ao.sx-mx);
        ld lc=mx*ao.sy-my*ao.sx;
        ld la2=(s2_endy-my);
        ld lb2=(mx-s2_endx);
        ld lc2=(s2_endx*my-s2_endy*mx);
        ld epsil=1e-12;
        auto foot_from_origin=[&](ld a,ld b,ld c,ld &fx,ld &fy)->bool {
            ld fracmom=a*a+b*b;
            if (fracmom<=epsil) return false;
            fx=-a*c/fracmom;
            fy=-b*c/fracmom;
            return true;
        };
        auto onseg=[&](ld fx,ld fy,ld x1,ld y1,ld x2,ld y2)->bool {
            ld dx=x2-x1;
            ld dy=y2-y1;
            ld d2=dx*dx+dy*dy;
            if (d2<=epsil) return false;
            ld tproj=((fx-x1)*dx+(fy-y1)*dy)/d2;
            return (tproj>=-epsil && tproj<=1.0l+epsil);
        };
        auto point_seg_dist=[&](ld a,ld b,ld c,ld x1,ld y1,ld x2,ld y2)->ld {
            if (fabsl(a)<=epsil && fabsl(b)<=epsil) {
                ld r=dist(0,0,x1,y1);
                chmin(r,dist(0,0,x2,y2));
                return r;
            }
            ld fx,fy;
            if (foot_from_origin(a,b,c,fx,fy) && onseg(fx,fy,x1,y1,x2,y2)) {
                return line_point_dist(a,b,c);
            }
            ld r=dist(0,0,x1,y1);
            chmin(r,dist(0,0,x2,y2));
            return r;
        };

        chmin(ans,point_seg_dist(la,lb,lc,ao.sx,ao.sy,mx,my));
        chmin(ans,point_seg_dist(la2,lb2,lc2,mx,my,ao.gx,ao.gy));
        anss[tt]=ans;
    }
    cout<<fixed<<setprecision(15);
    rep(i,tc) cout<<anss[i]<<nl;
}