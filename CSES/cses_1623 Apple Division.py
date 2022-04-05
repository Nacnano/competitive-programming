def solve(it, cnt):
    if it == n:
        return abs(s-2*cnt)
    else:
        return min(solve(it+1, cnt), solve(it+1, cnt+arr[it]))


n = int(input())
arr = list(int(i) for i in input().split(' '))
s=sum(arr)


print(solve(0,0))