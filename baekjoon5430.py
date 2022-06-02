T = int(input()) #number of test case

for t in range(T):
    p = input() #functions to be executed
    n = int(input()) #size of array
    arr = input()
    if n>0:
        arr = arr[1:-1]
        arr = list(arr.split(","))
        arr = [int(x) for x in arr]
    else:
        arr = []
    front = 0
    rear = n
    now = 1 #1 = front , -1 = rear
    for com in p:
        if com == 'R':
            now *= -1
        else:
            if now == 1:
                front += 1
            else:
                rear -= 1
    if front<=rear:
        if now == -1:
            print(str(arr[front:rear][::-1]).replace(' ',''))
        else:
            print(str(arr[front:rear]).replace(' ',''))
    else:
        print('error')
        
    
