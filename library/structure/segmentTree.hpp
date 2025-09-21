#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


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