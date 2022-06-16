N,K = [int(x) for x in input().split()]
coins = []
for _ in range(N):
    coins.append(int(input()))
coins = coins[::-1]
total = 0
i = 0
while K>0:
    total += int(K/coins[i])
    K = K - (int(K/coins[i]))*coins[i]
    i += 1
print(total)
