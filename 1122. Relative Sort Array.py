class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        relative = []
        count = Counter(arr1)
        
        for i in arr2:
            for j in arr1:
                if i == j:
                    relative.append(j)
                    count[j] -= 1
        x = len(relative)
        for k in range(len(arr1)):
            if count[arr1[k]] != 0:
                relative.append(arr1[k])
        relative[x:] = sorted(relative[x:])
        return relative
