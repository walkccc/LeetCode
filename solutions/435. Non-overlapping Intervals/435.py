class Solution:
  def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
    ans = 0
    currentEnd = -math.inf

    for interval in sorted(intervals, key=lambda x: x[1]):
      if interval[0] >= currentEnd:
        currentEnd = interval[1]
      else:
        ans += 1

    return ans
