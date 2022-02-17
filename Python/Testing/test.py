str = "kkkk"
res = 0 
count = 0
for i in range(1,len(str)):
    d = {}
    for j in range(len(str) - i + 1):
        subs = ''.join(sorted(str[j:j+i]))
        print(subs)
        if subs not in d:
            d[subs] = 1
        elif subs in d:
            d[subs] += 1
        res += d[subs] - 1
