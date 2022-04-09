def func(arr):
    if n < 2: return "YES"
    l, r = arr[0] + arr[1], arr[-1]
    
    for i in range(2, n//2+1):
        if r > l: return "YES"
        l, r = l + arr[i], r + arr[-i]
    return "YES" if r > l else "NO"
    
for _ in range(int(input()):
    n = int(input())
    a = sorted(list(map(int, input().split())))
    func(a)
