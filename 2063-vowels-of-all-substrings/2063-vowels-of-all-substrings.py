class Solution:
    def countVowels(self, word: str) -> int:
        N, vowel = len(word), {'a','e','i','o','u'}
        dp = [0] * N
        dp[0] = 1 if word[0] in vowel else 0
        for i in range(1,N):
            if word[i] in vowel:
                dp[i] = dp[i-1] + (i+1)
            else:
                dp[i] = dp[i-1]
                
        return sum(dp)