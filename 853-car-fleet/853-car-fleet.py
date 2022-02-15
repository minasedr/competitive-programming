class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        carFleets = []
        for pos, speed in sorted([(p,s) for p,s in zip(position,speed)], reverse=True):
            tar = (target - pos) / speed
            if not (carFleets and tar <= carFleets[-1]):
                carFleets.append(tar)
                
        return len(carFleets)   