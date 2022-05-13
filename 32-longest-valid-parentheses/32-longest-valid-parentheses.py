class Solution:
    def longestValidParentheses(self, s: str) -> int:
        ans, dp = 0, [0] * len(s)
        
        for i, ch in enumerate(s):
            if ch == ')':
                if i > 0 and s[i-1] == '(':
                    dp[i] = (dp[i-2] if i > 1 else 0) + 2
                else:
                    if i - dp[i-1] > 0 and s[i-dp[i-1]-1] == '(':
                        dp[i] = (dp[i-dp[i-1]-2] if i - dp[i-1] > 1 else 0) + dp[i-1] + 2
                ans = max(ans, dp[i])
                
        return ans
    
    
    