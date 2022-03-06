class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        freq = Counter(words)
        
        heap = []
        d = []
        for i, word in enumerate(words):
            if word not in d:
                d.append(word)
                heap.append((-freq[word], word))
                
        heapq.heapify(heap)
        
        ans = [heapq.heappop(heap)[1] for i in range(k)]
 
        return ans