class Solution:
  def getImportance(self, employees: List['Employee'], id: int) -> int:
    idToEmployee = {employee.id: employee for employee in employees}

    def dfs(id: int) -> int:
      values = idToEmployee[id].importance
      for subId in idToEmployee[id].subordinates:
        values += dfs(subId)
      return values

    return dfs(id)
