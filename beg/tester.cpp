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



void no() { cout<<"No"<<nl;}
void yes() { cout<<"Yes"<<nl;}
void yn(bool a) {
    cout<<(a ? "Yes":"No")<<nl;
}

ll sum(vector<ll>& a) {
    ll ans=0;
    for(auto i:a) ans+=i;
    return ans;
}

vector<ll> dx={-1,0,1,0};
vector<ll> dy={0,-1,0,1};

bool isin(ll i,ll j,ll h,ll w) {
    if(i<0 || i>=h || j<0 || j>=w) return false;
    return true;
}



string sp(string &s) { //manacher;
    string t="*#";
    rep(i,(ll)s.size()) {
        t+=s[i];
        t+="#";
    }
    t+="~";
    ll n=t.size();
    vector<ll> rad(n);
    int i=0,j=0;
    while(i<n) {
        while(i-j>=0 && i+j<n && t[i-j]==t[i+j]) ++j;
        rad[i]=j;
        int k=1;
        while(i-k>=0 && k+rad[i-k]<j) rad[i+k]=rad[i-k],++k;
        i+=k; j-=k;
    }
    rep(i,n) rad[i]--;
    
    int besti;
    rep(i,n) {
        if(i+rad[i]==n-2) {
            besti=i;break;
        }
        if(i==n-1) return "owari";
    }
    string add;
    ll truerad=(rad[besti]+1)/2;
    ll truei=(besti-rad[besti]+1-2)/2;
    add=s.substr(0,truei);
    reverse(all(add));
    return s+add;
}


vector<ll> pfact(ll n) {
    vector<ll> resp;
    vector<bool> prefact(sqrtl(n)+10);
    for(ll i=2;i*i<=n;i++) {
        while(n%i==0) {
            n/=i;
            if(!prefact[i]) resp.push_back(i);
            prefact[i]=true;
        }
    }
    if(n!=1) resp.push_back(n);
    return resp;
}

ll vecmax(vector<ll> &a) {
    ll ans=-INF;
    rep(i,(ll)a.size()) {
        ans=max(ans,a[i]);
    }
    return ans;
}

ll vecmin(vector<ll> &a) {
    ll ans=INF;
    rep(i,(ll)a.size()) {
        ans=min(ans,a[i]);
    }
    return ans;
}

ll safemod(ll num,ll rule) {
    return (num%rule+rule)%rule;
}

ll modinv(ll a, ll mod) { //拡張Euclidによるmodでの逆元, a*u+mod*v=1を解く
	ll b=mod,u=1,v=0;
	while (b) {
		ll t=a/b;
		a-=t*b;
        swap(a,b);
		u-=t*v;
        swap(u,v);
	}
	u%=mod; 
	if (u < 0) u+=mod;
	return u;
}

ll extgcd(ll a, ll b, ll &x, ll &y) { // ax+by=gcd(a,b) -> x,yを格納
    if (b==0) {
        x=1;
        y=0;
        return a;
    }
    ll d=extgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}


vector<ll> Erasieve(ll n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false; 

    for (int i=2;i*i<=n;++i) {
        if (is_prime[i]) {
            for (int j=i*i;j<=n;j+=i) is_prime[j] = false;
        }
    }
    vector<ll> primes;
    srep(i,2,n) {
        if (is_prime[i]) primes.push_back(i);
    }

    return primes;
}

vector<ll> Erasieve_segment(ll lef, ll rig) {
    ll M = floor(sqrt(rig)+100);
    vector<bool> isprime(M+1,true);
    isprime[0]=isprime[1]=false;
    for (ll p=2; p*p<=M; ++p) {
        if (!isprime[p]) continue;
        for (ll q=p*p; q<=M; q+=p) isprime[q]=false;
    }

    vector<bool> isp2(rig-lef+1,true);
    for (ll p=2; p<=M; ++p) {
        if (!isprime[p]) continue;
        ll start=max(p*p,((lef+p-1)/p)*p);
        for (ll q=start; q<=rig; q+=p)
            isp2[q-lef] = false;
    }
    vector<ll> res;

    for (ll x=max(lef,2LL) ; x<=rig ; ++x)
        if (isp2[x-lef])
            res.push_back(x);
    return res;
}



vector<vector<pair<ll,int>>> factor_range(ll L,ll R){ //lef以上rig以下のものの、素因数分解の結果を(因数、指数)で返す O(max(r-l,sqrt(r)))
    ll n=R-L+1;
    vector<ll> v(n);
    iota(v.begin(),v.end(),L);
    vector<vector<pair<ll,int>>> res(n);
    for(ll p=2; p*p<=R; ++p){
        ll s=max(p*p,(L+p-1)/p*p);
        for(ll j=s; j<=R; j+=p){
            int i=j-L, c=0;
            while(v[i] % p == 0) v[i]/=p, ++c;
            if(c) res[i].emplace_back(p,c);
        }
    }
    rep(i,n) if(v[i] > 1) res[i].emplace_back(v[i],1);
    return res;
}
ll divcount(ll n) {
    ll ans=0;
    for(int i=1;i*i<=n;i++) {
        if(n%i==0) ans+=(i*i==n ? 1:2);
    }
    return ans;
}

   
struct UnionFind {
    vector<int> par;
    vector<int> rank;
    int count;
    UnionFind(int N):par(N),rank(N,0),count(N){
        rep(i,N) par[i]=i;
    }
    //経路圧縮
    int root(int x){
        return par[x]==x?x:par[x]=root(par[x]);
    }
    void unite(int x,int y){
        int rx=root(x),ry=root(y);
        if(rx==ry) return;
        count--;
        if(rank[rx]<rank[ry]) {
            par[rx]=ry;
        }
        else {
            par[ry]=rx;
            if(rank[rx]==rank[ry]) rank[rx]++;
        }
    }
    bool same(int x,int y){
        return root(x)==root(y);
    }
    int comp_count() const{
        return count;
    }
};


struct XORPotentialUF {// 0-indexed!!...これABEL群に対応は...厳しいですね...
    vector<int> par;
    vector<int> wgt;  // 各ノードの根からの XOR 差分
    vector<int> rank; // 木の高さ的な

    XORPotentialUF(int size) : par(size),wgt(size,0),rank(size,0) {
        rep(i,size) par[i]=i;
    }

    pair<int, int> find(int u) {
        if (par[u]!=u) {
            int orig_par=par[u];
            auto [root,diff]=find(orig_par);
            par[u]=root;
            wgt[u]^=diff;
            return {root,wgt[u]};
        }
        return {u,0};
    }

    bool limitunite(int u,int v,int z) {
        auto [pu,ru]=find(u);
        auto [pv,rv]=find(v);
        if (pu==pv) {
            return (ru^rv)==z;
        }
        if (rank[pu]<rank[pv]) {
            swap(pu,pv);
            swap(ru,rv);
        }

        par[pv]=pu;
        wgt[pv]=ru^rv^z;

        if (rank[pu]==rank[pv]) rank[pu]++;

        return true;
    }

    int weight(int vertex) {
        find(vertex);
        return wgt[vertex];
    }

    int diff_ytox(int x,int y) {//使う気はしない
        return weight(x)^weight(y);
    }
};



template<class ABEL> struct ADDPotentialUF { //0-indexed!! reference: https://qiita.com/drken/items/cce6fc5c579051e64fab super感謝
	vector<int> par;
	vector<int> rank;
	vector<ABEL> wgt;

	ADDPotentialUF(int size) : par(size),wgt(size,0),rank(size,0) {
        rep(i,size) par[i]=i;
    }


	pair<int, ABEL> find(int x) {
        if (par[x]==x) {
            return {x,0};
        } else {
            auto [r,w]=find(par[x]);
            par[x]=r;
            wgt[x]+=w;
            return {r,wgt[x]};
        }
    }

	ABEL weight(int x) {
		find(x);
		return wgt[x];
	}

	bool issame(int x,int y) {
		return find(x).first==find(y).first;
	}

	bool unite(int x,int y,ABEL w) {
		w+=weight(x); w-=weight(y);
		x=find(x).first; y=find(y).first;
		if (x==y) {
            return (diff_ytox(x,y)==w);
        }
		if (rank[x]<rank[y]) swap(x,y), w*=-1;
		if (rank[x]==rank[y]) ++rank[x];
		par[y]=x;
		wgt[y]=w;
		return true;
	}

	ABEL diff_ytox(int x,int y) { //同じ成分にいる前提
		return weight(y)-weight(x);
	}
};


struct dictional_uf {
    public:
        unordered_map<ll,ll> par;
        unordered_map<ll,ll> rank;
        dictional_uf():par(),rank(){}
        void add(ll key) {
            par[key]=key;
            rank[key]=1;
        }
        ll find(ll x) {
            if(x==par[x]) return x;
            else return par[x]=find(par[x]);
        }
        bool unite(ll x,ll y) {
            ll px=find(x),py=find(y);
            if(px==py) return false;
            if(px<py) {
                par[px]=py;
                rank[py]+=rank[px];
                rank[px]=0;
            }
            else {
                par[py]=px;
                rank[px]=rank[py];
                rank[py]=0;
            }
            return true;
        }
        
};



template <class T> void vecpr(T first,T last) {
    ll tmp=0;
    for(auto it=first;it!=last;++it) {
        if(tmp) cout<<" ";
        cout<<*it;
        tmp++;
    }
    cout<<endl;
}



vector<ll> slmax(vector<ll> a, ll limit, ll breadth) {//slidewindowによる幅breadthでの区間最大値評価,limit=a.size()
    assert(limit==a.size());
    deque<ll> deq;
    vector<ll> max_numbers(limit, (-1)*INF);
    rep(i, limit) {
        while (!deq.empty() && deq.front() <= i - breadth) deq.pop_front();
        while (!deq.empty() && a[deq.back()] <= a[i]) deq.pop_back();
        deq.push_back(i);
        max_numbers[i] = a[deq.front()];
    }
    return max_numbers;
}

vector<ll> slmin(vector<ll> a, ll limit, ll breadth) {//slidewindowによる幅breadthでの区間最小値評価,limit=a.size()
    assert(limit==a.size());
    deque<ll> deq;
    vector<ll> min_numbers(limit, INF);
    rep(i, limit) {
        while (!deq.empty() && deq.front() <= i - breadth) deq.pop_front();
        while (!deq.empty() && a[deq.back()] >= a[i]) deq.pop_back();
        deq.push_back(i);
        min_numbers[i] = a[deq.front()];
    }
    return min_numbers;
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

ll gcd(ll a,ll b) {  //Euclid
    if(a<b) return gcd(b,a);
    if(a%b==0) return b;
    return gcd(b,a%b);
}

vector<ll> lis_size(vector<ll>& a) { // 最長増加部分列の a index目までみたのがdp[a];
    ll n=a.size();
    vector<ll> dp(n,1);  
    vector<ll> seq;       

   rep(i,n) {
        auto it=lower_bound(seq.begin(), seq.end(), a[i]);
        
        if (it==seq.end())  seq.push_back(a[i]);
        else *it=a[i];
        dp[i]=distance(seq.begin(), lower_bound(seq.begin(), seq.end(), a[i]))+1;
    }
    srep(i,1,n-1) {
        if(dp[i]<dp[i-1]) dp[i]=dp[i-1]; //ここをなくすと、"a[i]を末尾とするどうちゃら"になる
    }
    return dp;
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
        void set(ll ind,t val) {
            ind+=siz;
            seg[ind]=val;
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

class factset {
    public:
        vl _fact;
        vl _inv;
        ll __n;
        factset(ll n):_fact(n+1),_inv(n+1),__n(n) {
            _fact[0]=1;
            srep(i,1,__n) {
                _fact[i]=_fact[i-1]*i;
                _fact[i]%=mod;
            }
            _inv[__n]=modpow(_fact[__n],mod-2,1);
            for(int i=__n-1;i>=0;i--) {
                _inv[i]=_inv[i+1]*(i+1);
                _inv[i]%=mod;
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

        ll comb(ll nn,ll k,ll mode) {
            ll ans=1;
            ans*=_fact[nn];
            ans%=mod;
            ans*=_inv[nn-k];
            ans%=mod;
            ans*=_inv[k];
            return ans%mod;
        }
};

bool crt(ll a1,ll m1,ll a2,ll m2,ll &r,ll &lcm) {
    ll x,y;
    ll g=extgcd(m1,m2,x,y);
    if ((a2-a1)%g!=0) return false; // No sols.

    ll mod=m1/g*m2;
    ll tmp=((a2-a1)/g*x)%(m2/g);
    r=(a1+m1*tmp)%mod;
    if (r<0) r+=mod;
    lcm=mod;
    return true;
}

int main() {
    
}
