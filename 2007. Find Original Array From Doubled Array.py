class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        changed.sort(reverse=True)
        start, end, demo = 0, 1, []
        count = Counter(changed)
        
        if changed.count(0) % 2 == 1:
            return []
        
        demo = [0 for i in range(changed.count(0) // 2)]
        count[0] -= changed.count(0)
        
        while start < len(changed) and end < len(changed):
            if count[changed[start]] == 0:
                start += 1
            elif changed[start] == 2 * changed[end] and count[changed[end]] != 0:
                demo.append(changed[end])
                count[changed[start]] -= 1
                count[changed[end]] -= 1
                start += 1
                end += 1
            elif changed[start] < 2 * changed[end]:
                end += 1
            else:
                start += 1
        # return demo
        return demo if len(demo) == len(changed)/2 else []
