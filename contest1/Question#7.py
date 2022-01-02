symbols = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
total = 0
string = input()
for i in range(len(string)-1):
    if symbols[string[i]] < symbols[string[i+1]]:
        total -= symbols[string[i]]
    else:
        total += symbols[string[i]]
total += symbols[string[-1]]
print(total)
