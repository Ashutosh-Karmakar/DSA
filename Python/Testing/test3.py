# str = [10,4,3,10,25,2]
# str = [1,4,3]
str = [1,4,2,5,6]
n = 5
k =100
res = 0 
count = 0
li = []
result = []
for i in range(1,len(str)):
    for j in range(len(str) - i + 1):
        li.append(str[j:j+i])
li.append(str)
# print(li)

for i in li:
    if(sum(i) >= k):
        result.append(i)
# print(result)
count = 0
result2 = []
lista = []
for i in result:
    for j in i:
        if(sum(i) - j >= k and j not in lista):
            result2.append(j)
            lista.append(j)
            count += 1
if(count == 0):
    print(n)

else:
    print(count)

# print(lista)
# print(set(result2))
# # result = []
# # for i in range(len(li)):
# #     if(sum(li[i])>=k):
# #         result.append(li[i])

# # count = 0

# # result2 = []
# # for i in range(len(result)-1):
# #     for j in range(i+1,len(result)):
# #         if(len(result[j]) != len(result[i]) and (set(result[j]).intersection(set(result[i]))!=None)):
# #             print(result[i],result[j])
# #             result2.append(j)
#             count+=1
        
        
        
#         # l1 = result[i]
#         # l2 = result[j]
#         # if(len(l1) != len(l2)):
            
#         #     for l in l2:
#         #         if(l not in l1):
#         #             result2.append(l)

# print(result)

# print(set(result2))

# for i in str:
#     if i in result2:
#         count +=1
        
