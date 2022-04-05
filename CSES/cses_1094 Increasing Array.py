n=int(input())
arr=input().split(' ')
last=int(arr[0])
ans=0
for val in arr:
    if int(val) < last:
        ans+=(last-int(val))
    last=max(int(val),last)
print(ans)