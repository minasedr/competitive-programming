"""
   This is the custom function interface.
   You should not implement it, or speculate about its implementation
   class CustomFunction:
       # Returns f(x, y) for any given positive integers x and y.
       # Note that f(x, y) is increasing with respect to both x and y.
       # i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
       def f(self, x, y):
  
"""

class Solution:
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        ans = []
        for x in range(1,1001):
            l, r = 1, 1000
            while l <= r:
                y = (l + r) // 2
                res = customfunction.f(x,y)
                if res < z:
                    l = y + 1
                elif res > z:
                    r = y - 1
                else:
                    ans.append((x,y))
                    break     
        return ans