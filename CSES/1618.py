n = int(input())

ret = 0

while n:
    ret += (n//5)
    n //= 5

print(ret)