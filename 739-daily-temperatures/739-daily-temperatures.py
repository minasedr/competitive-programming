class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack, N = [], len(temperatures)
        result = [0] * N
        
        for idx in range(N):
            while stack and temperatures[stack[-1]] < temperatures[idx]:
                fill = stack.pop()
                result[fill] = (idx-fill)
            stack.append(idx)
            
        return result