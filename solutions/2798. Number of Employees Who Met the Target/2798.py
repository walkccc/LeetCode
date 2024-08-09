class Solution:
  def numberOfEmployeesWhoMetTarget(self, hours: List[int], target: int) -> int:
    return sum(hour >= target for hour in hours)
