# pattern 1
n = int(input())
for i in range(n+1):
    print(" " * (n - i), end="")
    print("*" * (2 * i - 1))
 
# pattern 2
n = int(input())
for i in range(n):
    print("*" * (i + 1))
