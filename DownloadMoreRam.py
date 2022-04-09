for _ in range(int(input()):
  n, k = map(int, input().split())
  a = list(map(int, input().split()))
  b = list(map(int, input().split()))
  
  ram, ans = sorted([a[i],b[i] for i in range(len(a))], k
  for i, n in enumerate(ram):
    if ans >= n[0]: ans += n[1]
  print(ans)
