import sys
input = sys.stdin.readline

N,M = [int(x) for x in input().split()]

notepad = {}

for _ in range(N):
    x,y = input().split()
    notepad[x] = y

for _ in range(M):
    x = input().rstrip()
    print(notepad[x])
