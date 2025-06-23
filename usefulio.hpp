template <class T> void vecpr(T first,T last) {Add commentMore actions
    ll tmp=0;
    for(auto it=first;it!=last;++it) {
        if(tmp) cout<<" ";
        cout<<*it;
        tmp++;
    }
    cout<<endl;
}

ll vecmax(vector<ll> &a) {
    ll ans=-1*INF;
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
