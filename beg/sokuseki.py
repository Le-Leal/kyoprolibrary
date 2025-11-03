n=int(input())

def cubicsum(n) :
    return (n*(n+1)//2)*(n*(n+1)//2)
MA=10**6+2
ans=[]
for i in range(1,MA) :
    lef=i-1
    rig=MA
    while(rig-lef>1) :
        mid=(rig+lef)//2
        if(cubicsum(mid)-cubicsum(i-1)>=n) :rig=mid
        else : lef=mid
    if(cubicsum(rig)-cubicsum(i-1)==n) :
        ans.append([i,rig])

print(len(ans))
for i in range(len(ans)) :
    print(ans[i][0],ans[i][1])