n = int(input())
if n % 4 == 0:
    print("YES")
    print(n//2)
    for i in range(1,n+1,4):
        print(str(i) + " " + str(i+3), end = " ")
    print("\n"+str(n//2))
    for i in range(1,n+1,4):

        print(str(i+1) + " " +str(i+2), end = " ")
elif n % 4 == 3:
    print("YES")
    print(n//2+1)
    print(1,2,end= " ")
    for i in range(4,n+1,4):
        print(str(i) + " " + str(i+3), end = " ")
    print("\n"+str(n//2))
    print(3,end = " ")
    for i in range(4,n+1,4):
        print(str(i+1) + " " +str(i+2), end = " ")

else:
    print("NO")



        