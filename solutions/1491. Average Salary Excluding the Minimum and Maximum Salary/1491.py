class Solution:
  def average(self, salary: list[int]) -> float:
    return (sum(salary) - max(salary) - min(salary)) / (len(salary) - 2)
