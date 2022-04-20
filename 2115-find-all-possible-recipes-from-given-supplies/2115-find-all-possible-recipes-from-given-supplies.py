class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        graph, ans = defaultdict(set), []
        inDegrees = [0] * len(recipes)
        
        for i in range(len(ingredients)):
            for gr in ingredients[i]:
                graph[gr].add(i)
                inDegrees[i] += 1
                
        q = deque([sup for sup in supplies])
        
        while q:
            p = q.popleft()
            sup = recipes[p] if str(p).isdecimal() else p
            if sup in recipes:
                ans.append(sup)
            for ne in graph[sup]:
                inDegrees[ne] -= 1
                if inDegrees[ne] == 0:
                    q.append(ne)
                    
        return ans
        