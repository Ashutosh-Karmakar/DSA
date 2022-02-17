f = open("blocklist.txt")
g = open("converted.txt",'w')
lines = f.readlines()
l = "var blocklist = ["
g.writelines(l)
for line in lines:
    line = line.replace("\n","")
    line = "\"*://*." + line + "/*\",\n"
    g.writelines(line)

l = "]"
g.writelines(l)
f.close()
g.close()

"*://*.zzz.onion.pet/*"