#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(ll i=0;i<n;i++)
#define EPSIL 1e-12
#define Winf 5e12

ld dist(ld x,ld y,ld x1,ld y1){
    ld p=(x1-x)*(x1-x)+(y1-y)*(y1-y);
    return sqrtl(p);
}

ld line_point_dist(ld a,ld b,ld c,ld px,ld py){
    ld f=a*a+b*b;
    if(f<=EPSIL) return Winf;
    return fabsl(a*px+b*py+c)/sqrtl(f);
}

bool foot_from_point(ld a,ld b,ld c,ld px,ld py,ld &fx,ld &fy){ //ax+by+c=0に(px,py)から垂線を下した時の足が入る
    ld f=a*a+b*b;
    if(f<=EPSIL) return false;
    fx=px-a*(a*px+b*py+c)/f;
    fy=py-b*(a*px+b*py+c)/f;
    return true;
}

bool onseg(ld fx,ld fy,ld x1,ld y1,ld x2,ld y2){ //線分(x1,y1)~(x2,y2)に(fx,fy)は乗る？三分探索版も欲しいな
    ld dx=x2-x1;
    ld dy=y2-y1;
    ld d2=dx*dx+dy*dy;
    if(d2<=EPSIL) return false;
    ld t=((fx-x1)*dx+(fy-y1)*dy)/d2;
    return t>=-EPSIL && t<=1.0l+EPSIL;
};

ld point_seg_dist(ld x1,ld y1,ld x2,ld y2,ld px,ld py){
    ld a=y2-y1,b=x1-x2,c=-(a*x1+b*y1);
    if(fabsl(a)<=EPSIL && fabsl(b)<=EPSIL){
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

ld point_seg_dist_ternarysearch(ld x1,ld y1,ld x2,ld y2,ld px,ld py){
    ld dx=x2-x1,dy=y2-y1;
    ld segd2=dx*dx+dy*dy;
    if(segd2<=EPSIL) return dist(px,py,x1,y1);
    ld l=0.0l,r=1.0l;
    rep(iter,100){
        ld m1=l+(r-l)/3.0l;
        ld m2=r-(r-l)/3.0l;
        ld x1t=x1+dx*m1,y1t=y1+dy*m1;
        ld x2t=x1+dx*m2,y2t=y1+dy*m2;
        ld dd1=(x1t-px)*(x1t-px)+(y1t-py)*(y1t-py);
        ld dd2=(x2t-px)*(x2t-px)+(y2t-py)*(y2t-py);
        if(dd1<dd2) r=m2; else l=m1;
    }
    ld t=(l+r)/2.0l;
    ld fx=x1+dx*t,fy=y1+dy*t;
    return sqrtl((fx-px)*(fx-px)+(fy-py)*(fy-py));
}