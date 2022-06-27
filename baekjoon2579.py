n = int(input())
stares = [0]
max_0 = [0]*(n+1)
max_1 = [0]*(n+1)

for _ in range(n):
    st = int(input())
    stares.append(st)

max_0[0] = 0
max_1[0] = 0
max_0[1] = stares[1]
max_1[1] = stares[1]
for i in range(2,n+1,1):
    max_0[i] = max([max_0[i-2],max_1[i-2]]) + stares[i]
    max_1[i] = max_0[i-1] + stares[i]
   

print(max([max_0[n],max_1[n]]))
