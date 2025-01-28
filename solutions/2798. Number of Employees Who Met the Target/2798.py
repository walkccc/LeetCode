class Solution:
  def numberOfEmployeesWhoMetTarget(self, hours: list[int], target: int) -> int:
    return sum(hour >= target for hour in hours)
