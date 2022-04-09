class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        count, canBan = Counter(senate), Counter(senate)
        
        if len(senate) == 1:
            return "Radiant" if senate[0] == 'R' else "Dire"
        
        for sen in senate:
            if not (canBan['D'] and canBan['R']):
                break
            if sen == 'R' and count['R']:
                count['D'] -= 1
            elif sen == 'D' and count['D']:
                count['R'] -= 1
            canBan['D'] -= 1
            canBan['R'] -= 1
                
        return "Radiant" if count['D'] < count['R'] else "Dire"