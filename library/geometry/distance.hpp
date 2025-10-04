#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(ll i=0;i<n;i++)
#define epsil 1e-12
#define Winf 5e12

ld dist(ld x,ld y,ld x1,ld y1){
    ld p=(x1-x)*(x1-x)+(y1-y)*(y1-y);
    return sqrtl(p);
}

ld line_point_dist(ld a,ld b,ld c,ld px,ld py){
    ld f=a*a+b*b;
    if(f<=epsil) return Winf;
    return fabsl(a*px+b*py+c)/sqrtl(f);
}

bool foot_from_point(ld a,ld b,ld c,ld px,ld py,ld &fx,ld &fy){ //ax+by+c=0に(px,py)から垂線を下した時の足が入る
    ld f=a*a+b*b;
    if(f<=epsil) return false;
    fx=px-a*(a*px+b*py+c)/f;
    fy=py-b*(a*px+b*py+c)/f;
    return true;
}

bool onseg(ld fx,ld fy,ld x1,ld y1,ld x2,ld y2){ //線分(x1,y1)~(x2,y2)に(fx,fy)は乗る？三分探索版も欲しいな
    ld dx=x2-x1;
    ld dy=y2-y1;
    ld d2=dx*dx+dy*dy;
    if(d2<=epsil) return false;
    ld t=((fx-x1)*dx+(fy-y1)*dy)/d2;
    return t>=-epsil && t<=1.0l+epsil;
};

ld point_seg_dist(ld a,ld b,ld c,ld x1,ld y1,ld x2,ld y2,ld px,ld py){ // ax+by+c=0 ([x1,x2] and [y1,y2])と(px,py)の最小距離 O(1)
    assert(fabsl(a*x1+b*y1+c)<=epsil && fabsl(a*x2+b*y2+c)<=epsil); //あってる？
    if(fabsl(a)<=epsil && fabsl(b)<=epsil){
        ld r=dist(px,py,x1,y1);
        r=min(r,dist(px,py,x2,y2));
        return r;
    }
    ld fx,fy;
    if(foot_from_point(a,b,c,px,py,fx,fy) && onseg(fx,fy,x1,y1,x2,y2))
        return line_point_dist(a,b,c,px,py);
    ld r=dist(px,py,x1,y1);
    r=min(r,dist(px,py,x2,y2));
    return r;
}


ld point_seg_dist_ternarysearch(ld a,ld b,ld c,ld x1,ld y1,ld x2,ld y2,ld px,ld py){ //上と同じ。誤差少なめだけど100iterationくらいする
    assert(fabsl(a*x1+b*y1+c)<=epsil && fabsl(a*x2+b*y2+c)<=epsil);
    ld l=0.0l,r=1.0l;
    rep(iter,100) {
        ld m1=l+(r-l)/3.0l;
        ld m2=r-(r-l)/3.0l;
        ld x1t=x1+(x2-x1)*m1;
        ld y1t=y1+(y2-y1)*m1;
        ld x2t=x1+(x2-x1)*m2;
        ld y2t=y1+(y2-y1)*m2;
        ld d1=dist(px,py,x1t,y1t);
        ld d2=dist(px,py,x2t,y2t);
        if(d1<d2) r=m2; else l=m1;
    }
    ld t=(l+r)/2.0l;
    ld fx=x1+(x2-x1)*t;
    ld fy=y1+(y2-y1)*t;
    return dist(px,py,fx,fy);
}