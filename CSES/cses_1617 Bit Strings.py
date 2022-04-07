n = int(input())
ans=1
for i in range(0,n,1):
    ans = ans * 2
    ans = ans % int(1e9+7)
print(ans)