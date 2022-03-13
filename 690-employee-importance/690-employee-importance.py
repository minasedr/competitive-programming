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
        total = 0
        for emp in employees:
            if emp.id == id:
                for sub in emp.subordinates:
                    total += self.getImportance(employees,sub)
                return total + emp.importance