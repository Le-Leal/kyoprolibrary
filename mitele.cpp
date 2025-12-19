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
    cout<<nl<<nl;
}
template<typename t> class segtree {
    function<t(t,t)> op;
    function<t()> e;
    ll n;
    vector<t> seg;
    ll siz=1;
    public:
        segtree(ll n,function<t(t,t)> op,function<t()> e) : n(n),op(op),e(e) {
            while(siz<n) siz*=2;
            seg = vector<t>(2*siz,e());
        }


        segtree(const vector<t>& v, function<t(t,t)> op, function<t()> e):segtree((ll)v.size(), op, e) {
            for (ll i=0;i<(ll)v.size();++i) seg[siz+i]=v[i];
            for (ll i=siz-1;i>0;--i) seg[i]=op(seg[2*i],seg[2*i+1]);
        }

        void set(ll ind,t val) {
            ind+=siz;
            seg[ind]=val;
            while(ind>>=1) seg[ind]=op(seg[2*ind],seg[2*ind+1]);
        }

        void add(ll ind,t val) {
            ind+=siz;
            seg[ind]=op(seg[ind],val);
            while(ind>>=1) seg[ind]=op(seg[2*ind],seg[2*ind+1]);
        }

        t one_p(ll ind) {
            return seg[ind+siz];
        }

        t prod(ll lef,ll rig) { // [l,r)
            lef+=siz,rig+=siz;
            t opl=e(),opr=e();
            for(;lef<rig;lef>>=1,rig>>=1) {
                if(lef&1) opl=op(opl,seg[lef++]);
                if(rig&1) opr=op(seg[--rig],opr);
            }
            return op(opl,opr);
        }

        template<class c> ll max_right(ll lef,c judge) {
            ll LEF=lef+siz,wid=1; //LEF=seg列上の位置,lef=配列上のindex
            t ansl=e();
            for(;lef+wid<=n;LEF>>=1,wid<<=1) if(LEF&1) {
                if(!judge(op(ansl,seg[LEF]))) break;
                ansl=op(ansl,seg[LEF++]);
                lef+=wid;
            }
            while(LEF<<=1,wid>>=1) {
                //if(wid==0) break;
                if(lef+wid<=n && judge(op(ansl,seg[LEF]))) {
                    ansl=op(ansl,seg[LEF++]);
                    lef+=wid;
                }
            }
            return lef;
        }

        template<class c> ll min_left(ll rig,c judge) {
            ll RIG=rig+siz,wid=1;
            t ansr=e();
            for(;rig-wid>=0;RIG>>=1,wid<<=1) if(RIG&1) {
                if(!judge(op(seg[RIG-1],ansr))) break;
                ansr=op(seg[--RIG],ansr);
                rig-=wid;
            }
            while(RIG<<=1,wid>>=1) {
                //if(wid==0) break;
                if(rig-wid>=0 && judge(op(seg[RIG-1],ansr))) {
                    ansr=op(seg[--RIG],ansr);
                    rig-=wid;
                }
            }
            return rig;
        }
};
ll opmax(ll a,ll b) {
    return max(a,b);
}
ll emax() {
    return -1e16;
}
ll opmin(ll a,ll b) {
    return min(a,b);
}
ll emin() {
    return 1e16;
}

struct query {
    ll l,r,x;
    ll id;
};


int main() {
    ll n,m,p; cin>>n>>m>>p;
    vector<vector<pair<ll,ll>>> temp(n);
    rep(i,m) {
        ll a,b,c; cin>>a>>b>>c;
        temp[--b].emplace_back(--a,c);
    }
    
    ll q; cin>>q;
    srep(i,1,n-1) {
        if(temp[i].size()==0) {
           rep(j,q) no();
            return 0;
        }
    }
    vector<query> qrs(q,{0,0,0});
    rep(i,q) {
        ll le,ri,x; cin>>le>>ri>>x;
        qrs[i]={le,ri,x,i};
    }
    sort(all(qrs),[&](query a,query b) {return a.l<b.l;});
    vector<pair<ll,ll>> best_itv(n,{1e10,-1e10}); //best itv[L,R] which satisfy 1->v
    srep(i,1,n-1) {
        ll lef=0,rig=1e12;
        for(auto [a,c]:temp[i]) {
            ll le=min(best_itv[a].first,c),ri=max(best_itv[a].second,c);
            if(rig-lef>ri-le) {
                rig=ri,lef=le;
            }
            else if(rig-lef==ri-le && lef<le) {
                rig=ri,lef=le;
            }
        }
        best_itv[i]={lef,rig};
    }
    vector<ll> ans1(q),ans2(q),ans3(q);
    vector<ll> comp_lef,comp_rig,comp_rl;
    rep(i,n) {
        comp_lef.pb(best_itv[i].first);
        comp_rig.pb(best_itv[i].second);
        comp_rl.pb(best_itv[i].second-best_itv[i].first);
    }
    sort(all(best_itv));
    uniq(comp_rl);
    uniq(comp_lef);
    uniq(comp_rig);
    
    segtree<ll> seglef(comp_lef.size(),opmax,emax);
    segtree<ll> segrig(comp_rig.size(),opmin,emin);
    segtree<ll> segrl(comp_rl.size(),opmax,emax);
    ll seen=0;
    rep(i,q) {
        auto [le,ri,xx,id]=qrs[i];
        while(best_itv[seen].first<=le) {
            ll idx=lower_bound(all(comp_rig),best_itv[seen].second)-comp_rig.begin();
            segrig.set(idx,best_itv[seen].second);
            seen++;
        }
        ll pos=lower_bound(all(comp_rig),ri+1)-comp_rig.begin();
        ans1[i]=segrig.prod(pos,comp_rig.size())-ri;
    }
    seen=n-1;
    irep(i,q-1,0) {
        auto [le,ri,xx,id]=qrs[i];
        while(best_itv[seen].first>le) {
            ll idx=lower_bound(all(comp_lef),best_itv[seen].first)-comp_lef.begin();
            seglef.set(idx,best_itv[seen].first);
            seen--;
        }
        ll pos=lower_bound(all(comp_rig),ri+1)-comp_rig.begin();
        ans2[i]=le-seglef.prod(0,pos);
    }
    seen=n-1;
    irep(i,q-1,0) {
        auto [le,ri,xx,id]=qrs[i];
        while(best_itv[seen].first>le) {
            ll idx=lower_bound(all(comp_rl),best_itv[seen].second-best_itv[seen].first)-comp_rl.begin();
            segrl.set(idx,best_itv[seen].second-best_itv[seen].first);
            seen--;
        }
        ll pos=lower_bound(all(comp_rig),ri+1)-comp_rig.begin();
        ans3[i]=segrl.prod(pos,comp_rl.size())-(ri-le);
    }
    vector<string> anss(q);
    rep(i,q) {
        ll ans=max({ans1[i],ans2[i],ans3[i]});
        if(ans<=qrs[i].x) anss[qrs[i].id]="Yes";
        else anss[qrs[i].id]="No";
    }
    rep(i,q) cout<<anss[i]<<nl;
}
