from string import ascii_uppercase

string = input()
mm ={}
for i in ascii_uppercase:
    mm[i]=0
for c in string:
    mm[c] = mm[c] + 1

odd=0
cnt=0
for i in ascii_uppercase:
    if mm[i] % 2 == 1:
        cnt = cnt + 1
        odd=i

if cnt > 1:
    print("NO SOLUTION")
else:
    for i in range(0,26,1):
        c=ascii_uppercase[i]
        sz = mm[c]
        for j in range(0,sz//2,1):
            print(c, end="")
            
    if cnt==1:
        print(odd, end="")

    for i in range(25,-1,-1):
        c=ascii_uppercase[i]
        sz = mm[c]
        for j in range(0,sz//2,1):
            print(c, end="")