M,N = [int(x) for x in input().split()]
min_total = 2500

chess = []
for _ in range(M):
    i = input()
    chess.append(i)

for i in range(0,M-7):
    for j in range(0,N-7):
        total1 = 0
        total2 = 0
        for m in range(i,i+8):
            for n in range(j,j+8):
                if (((m + n) % 2) == 0) ^ (chess[m][n]=='W'):
                    total1 += 1
                if (((m + n) % 2) == 0) ^ (chess[m][n]=='B'):
                    total2 += 1
        if total1 > M*N - total1:
            total1 = M*N - total1
        if total2 > M*N - total2:
            total2 = M*N - total2
        if min_total > total1:
            min_total = total1
        if min_total > total2:
            min_total = total2

print(min_total)
    
