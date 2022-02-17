# def sortby(s1,s2):
#     n1 = int(s1.substr(3,s1.length()));
#     n2 = int(s2.substr(3,s1.length()));
#     return n1 < n2;

# li = ['ab-1', 'ab-021', 'ab-201', 'ab-011', 'ab-12','ab-22']
# sorted(li, sortby)
# print(li)


s = "aab ssddde tya"

temp = s[0]
ans = temp
for i in s:
    if temp == i:
        pass
    if temp != i:
        temp = i
        ans += temp
    
print(ans)
    