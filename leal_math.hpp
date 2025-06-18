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