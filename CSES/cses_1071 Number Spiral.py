t = int(input())
for i in range(t):
    y, x = map(int, input().split())
    if x >= y:
        if x & 1 == 0:
            ans = (x-1)**2+y
        else:
            ans = x**2-y+1
    else:
        if y & 1 == 1:
            ans = (y-1)**2+x
        else:
            ans = y**2-x+1
    print(ans)