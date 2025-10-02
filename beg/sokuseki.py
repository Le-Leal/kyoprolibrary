t,m=map(int,input().split())
fact=[1 for i in range(5006)]
fact[0]=1
for i in range(1,5005+1) :
    fact[i]=fact[i-1]*i

while(t) :
    t-=1
    n=int(input())
    c=list(map(int,input().split()))
    ans=1
    ans*=fact[sum(c)]
    for i in range(n) :
        ans//=fact[c[i]]
    print(ans%m)