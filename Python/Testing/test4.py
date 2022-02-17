def contSum(n,d,x):
    res = '1'
    last = '9'
    for i in range(n-1):
        res = res + '0'
        last = last + '9'

    last = int(last)
    res = int(res)
    sum = 0

    for i in range(res,last+1):
        if i%d == x:
            sum += i
            
    return sum%(pow(10, 9)+7)

    
    
    
n = 2
d = 4
x = 3
print(contSum(n,d,x))