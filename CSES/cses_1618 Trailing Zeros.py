n = int(input())
div=5
ans=0
while div<=n:
    ans = ans + n // div
    div = div * 5
print(ans)
