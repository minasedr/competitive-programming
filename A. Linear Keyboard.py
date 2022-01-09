test = int(input())
results = []
for _ in range(test):
    keybr = input()
    word = input()
    time = 0
    for i in range(len(word) - 1):
        time += abs(keybr.index(word[i + 1]) - keybr.index(word[i]))
    results.append(time)
for i in results:
    print(i)
