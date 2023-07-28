class Solution:
  def findMaximalUncoveredRanges(self, n: int, ranges: List[List[int]]) -> List[List[int]]:
    ans = []
    start = 0

    for l, r in sorted(ranges):
      if start < l:
        ans.append([start, l - 1])
      if start <= r:
        start = r + 1

    if start < n:
      ans.append([start, n - 1])

    return ans
