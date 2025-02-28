class Solution:
  def insert(self, intervals: list[list[int]],
             newInterval: list[int]) -> list[list[int]]:
    n = len(intervals)
    ans = []
    i = 0

    while i < n and intervals[i][1] < newInterval[0]:
      ans.append(intervals[i])
      i += 1

    # Merge overlapping intervals.
    while i < n and intervals[i][0] <= newInterval[1]:
      newInterval[0] = min(newInterval[0], intervals[i][0])
      newInterval[1] = max(newInterval[1], intervals[i][1])
      i += 1

    ans.append(newInterval)

    while i < n:
      ans.append(intervals[i])
      i += 1

    return ans
