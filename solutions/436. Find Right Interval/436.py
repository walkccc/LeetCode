from sortedcontainers import SortedDict


class Solution:
  def findRightInterval(self, intervals: list[list[int]]) -> list[int]:
    ans = []
    startToIndex = SortedDict()

    for i, (start, end) in enumerate(intervals):
      startToIndex[start] = i

    for start, end in intervals:
      i = startToIndex.bisect_left(end)
      ans.append(-1 if i == len(startToIndex) else startToIndex.peekitem(i)[1])

    return ans
