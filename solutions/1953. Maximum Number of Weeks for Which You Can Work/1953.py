class Solution:
  def numberOfWeeks(self, milestones: list[int]) -> int:
    # The best strategy is to pick 'max, nonMax, max, nonMax, ...'.
    summ = sum(milestones)
    nonMax = summ - max(milestones)
    return min(summ, 2 * nonMax + 1)
