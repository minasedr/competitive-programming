class Solution:
    def average(self, salary: List[int]) -> float:
        total, div, salary = 0, len(salary) - 2, sorted(salary)
        
        for i in range(1, len(salary) - 1):
            total += salary[i]
            
        return total/div