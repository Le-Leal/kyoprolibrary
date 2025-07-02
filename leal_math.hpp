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



vector<vector<pair<ll,int>>> factor_range(ll L,ll R){ //lef以上rig以下のものの、素因数分解の結果を(因数、指数)で返す O(max(r-l,sqrt(r))) //遅め
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
