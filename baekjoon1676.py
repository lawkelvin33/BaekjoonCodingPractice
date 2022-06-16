N = int(input())
while N%5!=0:
    N-=1
five = 0
for i in range(N,0,-5):
    if i%5==0:
        five += 1
        if i%25==0:
            five += 1
            if i%125==0:
                five += 1
        
print(five)

