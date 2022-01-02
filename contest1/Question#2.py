def generatePat(n):
    i = 1
    while i <= (n + 4) / 2:
        print("*" * i, end="")
        print(" " * ((n + 4) - (2 * i)), end="")
        print("*" * i)
        i += 1

generatePat(int(input()))
