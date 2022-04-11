n, m, k = map(int, input().split(' '))
a = sorted(map(int, input().split(' ')))
b = sorted(map(int, input().split(' ')))
it1, it2, ans = 0, 0, 0

while it1 < n and it2 < m:
    if a[it1] + k < b[it2]:
        it1 = it1 + 1
    elif a[it1] - k > b[it2]:
        it2 = it2 + 1
    else:
        ans= ans + 1
        it1 = it1 + 1
        it2 = it2 + 1

print(ans)
