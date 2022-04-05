str=input()

ans=0
cnt=0
tmp=''
for c in str:
    if c!=tmp:
        cnt=1
        tmp=c
    else:
        cnt+=1
    ans=max(ans,cnt)
print(ans)
