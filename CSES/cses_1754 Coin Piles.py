t=int(input())
ans=[]
for q in range(0,t):
    arr=list(int(i) for i in input().split())
    s=sum(arr)
    if (s%3==0 and 2*min(arr)>=max(arr)) or s==0:
        ans.append("YES")
    else:
        ans.append("NO")
for i in ans:
    print(i)