testcases = int(input())
nums = []
for _ in range(testcases):
    length = int(input())
    arr = list(map(int, input().split()))
    results = []
    for i in arr:
        if i not in results:
            results.append(i)
        elif -i not in results:
            results.append(-i)
        else:
            continue
    nums.append(len(results))
for i in nums:
    print(i)
