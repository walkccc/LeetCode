class Solution:
  def minConnectedGroups(self, intervals: list[list[int]], k: int) -> int:
    mergedIntervals = 0
    maxMergedIntervals = 0

    intervals = self._merge(intervals)

    i = 0
    for _, end in intervals:
      while i < len(intervals) and end + k >= intervals[i][0]:
        mergedIntervals += 1
        i += 1
      mergedIntervals -= 1  # Exclude intervals[i].
      maxMergedIntervals = max(maxMergedIntervals, mergedIntervals)

    return len(intervals) - maxMergedIntervals

  # Same as 56. Merge Intervals
  def _merge(self, intervals: list[list[int]]) -> list[list[int]]:
    res = []
    for interval in sorted(intervals):
      if not res or res[-1][1] < interval[0]:
        res.append(interval)
      else:
        res[-1][1] = max(res[-1][1], interval[1])
    return res
