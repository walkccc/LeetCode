class Solution:
  def minimumEffort(self, tasks: list[list[int]]) -> int:
    ans = 0
    prevSaved = 0

    for actual, minimum in sorted(tasks, key=lambda x: x[0] - x[1]):
      if prevSaved < minimum:
        ans += minimum - prevSaved
        prevSaved = minimum - actual
      else:
        prevSaved -= actual

    return ans
