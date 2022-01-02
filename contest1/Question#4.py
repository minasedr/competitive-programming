# pattern 1
def generatePat(n):
    for i in range(1, n + 1):
        print(" " * (n - i), end="")
        print(int("1" * i) ** 2)


generatePat(int(input()))

# pattern 2
def generatePat(n):
    for i in range(1, n + 1):
        print(" " * (n - i), end="")
        print((int("1" * i)) ** 2)

    for j in range(n - 1, 0, -1):
        print(" " * (n - j), end="")
        print(int("1" * j) ** 2)


generatePat(int(input()))

# pattern 3
def generatePat(n):
    for i in range(1, n + 3):
        if i % 2 != 0:
            print("##  " * n, end="")
        else:
            print("  ##" * (n - 1), end="")
        print()
    return ""


print(generatePat(int(input())))
