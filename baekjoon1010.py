T = int(input())
for _ in range(T):
    N, M = [int(x) for x in input().split()]
    j = 1
    rst = 1
    for i in range(M-N+1,M+1):
        rst *= i
        rst /= j
        j += 1
    print(int(rst))
