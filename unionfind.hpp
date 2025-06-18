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