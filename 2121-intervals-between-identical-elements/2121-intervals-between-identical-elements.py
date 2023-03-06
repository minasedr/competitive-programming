class Solution:
    def getDistances(self, arr: List[int]) -> List[int]:
        
        store = defaultdict(list)
        
        for index, val in enumerate(arr):
            store[val].append(index)
        
        prefixes = defaultdict()
        suffixes = defaultdict()
        
        for key, value in store.items():
            
            prefixes[key] = deque([0])
            suffixes[key] = deque([0])
            n = len(value)
            
            for index in range(1, n):
                diff = value[index]-value[index-1]
                prefixes[key].append(prefixes[key][-1] + diff*index)
                
                #suffixes
                right = n-index-1
                suffix_diff = value[right+1]-value[right]
                suffixes[key].appendleft(suffixes[key][0] + suffix_diff * (n-right-1))
        
        answer = [0] * len(arr)
        for index, val in enumerate(arr):
            left = prefixes[val].popleft()
            right= suffixes[val].popleft() 
            answer[index] = left + right
        
        return answer