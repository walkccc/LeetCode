class Solution:
  def removeCoveredIntervals(self, intervals: list[list[int]]) -> int:
    ans = 0
    prevEnd = 0

    # If the two intervals have the same `start`, put the one with a larger
    # `end` first.
    for _, end in sorted(intervals, key=lambda x: (x[0], -x[1])):
      # Current interval is not covered by the previous one.
      if prevEnd < end:
        ans += 1
        prevEnd = end

    return ans
