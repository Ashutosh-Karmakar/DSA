from collections import Counter
arr = [1,5,5,25,125]
r = 5
d = {}
count = Counter(arr)
print(count)
for i,j in count.items():
    count[i] = count[i*r]
print(count)
value = list(count.values())
print(value)
res = value[0]
print(res)
resCount = 0
for i in range(1,len(value)):
    res = res * value[i]
    resCount += res
print(resCount)
# return
# 