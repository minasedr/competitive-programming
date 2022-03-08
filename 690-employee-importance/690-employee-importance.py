"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        self.total = 0
       
        store = defaultdict(int)
        for i,j in enumerate(employees):
            store[j.id] = i
        def dfs(Id):
            self.total += employees[store[Id]].importance
            for s in employees[store[Id]].subordinates:
                dfs(s)
        dfs(id)        
        return self.total