for i in range(1,9,2) :
    for j in range(i):
        print("*",end=" ")
    print()

print()
for i in range(1,6) :
    for j in range(1,4) :
        print("*", end=" ")
    print()


print()

x,y = 0,1
while(y<10) :
    print(y,end=' ')
    x,y = y, x+y