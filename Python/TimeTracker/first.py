# from AppKit import NSWorkspace
# import time

# active_window_name = ""
# while True:
#     new_window_name = (NSWorkspace.sharedWorkspace()
#                        .activeApplication()['NSApplicationName'])
#     if active_window_name != new_window_name:
#         active_window_name = new_window_name
#         print(active_window_name)
#     time.sleep(10)

res = '1'
n = 2
last = '9'
d = 4
x = 3
count = 0
for i in range(n-1):
    res = res + '0'
    last = last + '9'
print(res,last)

last = int(last)
res = int(res)
print(res,last)
sum = 0

for i in range(res,last+1):
    if i%d == x:
        print(i)
        count += 1
        sum += i
        
print(sum)
print(count)