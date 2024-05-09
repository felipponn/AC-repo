# 2024-03-19
# Title: Relational Operator
# Complexity: O(1)
# Difficulty: 1
n = int(input())
for _ in range(n):
  a, b = [int(x) for x in input().split()]
  if a > b:
    print('>')
  elif a==b:
    print('=')
  else:
    print('<')