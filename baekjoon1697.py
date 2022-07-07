from collections import deque
queue = deque([])
record = {}

n,k = list(map(int,input().split()))
exit = 0
time = 0
queue.append(n)
size = len(queue)
if n != k:
    while exit==0:
        time += 1
        for _ in range(size):
            tmp = queue.popleft()
            if tmp<k:
                a,c = tmp*2, tmp+1
                if a != k:
                    if a not in record:
                        queue.append(a)
                        record[a] = time
                else:
                    exit = 1
                    break 
                    
                if c != k:
                    if c not in record:
                        queue.append(c)
                        record[c] = time
                else:
                    exit = 1
                    break
            b = tmp-1
            if b != k:
                    if b not in record:
                        if b >= 0:
                            queue.append(b)
                            record[b] = time
            else:
                exit = 1
                break
        size = len(queue)            
            
print(time)            
            
            
            
