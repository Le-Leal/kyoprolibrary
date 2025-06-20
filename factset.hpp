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
        ll inv(x) {
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
