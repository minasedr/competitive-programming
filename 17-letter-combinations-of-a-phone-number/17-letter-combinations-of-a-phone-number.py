class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        result, n  = [], len(digits)
        if n == 0: return ""

        store = {'2':['a','b','c'], '3':['d','e','f'], 
                '4':['g','h','i'], '5': ['j','k','l'], 
                '6':['m','n','o'], '7':['p','q','r','s'], 
                '8':['t','u','v'], '9':['w','x','y','z']}
        
        def f(i, stack):
            if len(stack) == n:
                result.append(''.join(stack))
                return
            
            for ch in store[digits[i]]:
                stack.append(ch)
                f(i+1, stack)
                stack.pop()
            return result
        
        return f(0, [])
