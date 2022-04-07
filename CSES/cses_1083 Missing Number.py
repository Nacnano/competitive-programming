n=int(input())
ans=int(n*(n+1)/2)
arr=input().split(' ')
for val in arr:
    ans-=int(val)
print(int(ans))
