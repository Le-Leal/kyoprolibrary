#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<n;i++)

struct XORPotentialUF {//probably no use?
    vector<int> par;
    vector<ll> wgt;  // 各ノードの根からの XOR 差分
    vector<ll> rank; // 木の高さ的な

    XORPotentialUF(int size) : par(size),wgt(size,0),rank(size,0) {
        rep(i,size) par[i]=i;
    }

    pair<ll,ll> find(int u) {
        if (par[u]!=u) {
            int orig_par=par[u];
            auto [root,diff]=find(orig_par);
            par[u]=root;
            wgt[u]^=diff;
            return {root,wgt[u]};
        }
        return {u,0};
    }

    bool limitunite(int u,int v,ll z) {
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

    ll weight(int vertex) {
        find(vertex);
        return wgt[vertex];
    }

    ll diff_ytox(int x,int y) {//使う気はしない
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