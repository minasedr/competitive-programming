class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res, N = [], len(digits)
        if N == 0:
            return ""

        chmap = {'2':['a','b','c'], '3':['d','e','f'], 
                '4':['g','h','i'], '5': ['j','k','l'], 
                '6':['m','n','o'], '7':['p','q','r','s'], 
                '8':['t','u','v'], '9':['w','x','y','z']}
        
        def f(i, cur):
            if len(cur) == N:
                res.append(cur)
                return
            
            for ch in chmap[digits[i]]:
                f(i+1, cur+ch)
                
            return res
        return f(0, "")