arr, j = list(map(int, input().split())), 0
if len(arr) == 0:
    arr = []
else:
    for i in range(len(arr)):
        if arr[i] != 0:
            arr[j] = arr[i]
            j += 1
    for k in range(j, len(arr)):
        arr[k] = 0
print(arr)
