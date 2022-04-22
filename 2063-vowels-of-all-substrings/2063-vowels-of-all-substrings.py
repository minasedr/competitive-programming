class Solution:
    def countVowels(self, word: str) -> int:
        vowel = {'a','e','i','o','u'}
        cur = prev = 1 if word[0] in vowel else 0
        for i in range(1, len(word)):
            prev = (prev+(i+1) if word[i] in vowel else prev)
            cur += prev
        return cur