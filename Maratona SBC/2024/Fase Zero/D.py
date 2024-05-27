e, v = [int(x) for x in input().split()]
h = (e//v + 19)%24
m = (e%v)*60//v
if h < 10:
    print("0"+str(h), end='')
else:
    print(str(h), end='')
print(":",end='')
if m < 10:
    print("0"+str(m))
else:
    print(str(m))