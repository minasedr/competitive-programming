class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls = cows = 0
        count = Counter(secret)  
        
        for i in range(len(secret)):
            if guess[i] in count:
                if guess[i] == secret[i]:
                    bulls += 1
                    if count[guess[i]] <= 0:
                        cows -= 1
                elif count[guess[i]] > 0:
                    cows += 1
                count[guess[i]] -= 1

        return f"{bulls}A{cows}B"
