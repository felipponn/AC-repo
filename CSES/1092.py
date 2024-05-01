n = int(input())
SUM = n*(n+1)/2

if SUM % 2 == 1:
    print("NO")

else:
    print("YES")
    set1 = []
    atu = n
    META = SUM/2
    while sum(set1) < META:
        if atu <= META - sum(set1):
            set1.append(atu)
            atu -= 1
        else:
            set1.append(int(META - sum(set1)))
    print(len(set1))
    print(' '.join(str(x) for x in set1))
    print(n-len(set1))
    print(' '.join(str(x) for x in range(1, n+1) if x not in set1))