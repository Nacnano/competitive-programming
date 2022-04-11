ss = set()
n = int(input())
ls = list(int(i) for i in input().split(' '))
for i in ls:
    ss.add(i)
print(len(ss))