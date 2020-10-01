class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        def dfs(id: int) -> int:
            subordinatesImportance = sum(
                dfs(subordinate) for subordinate in idToEmployee[id].subordinates)
            return idToEmployee[id].importance + subordinatesImportance

        idToEmployee = {employee.id: employee for employee in employees}

        return dfs(id)
