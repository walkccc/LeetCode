class Solution:
  def countWays(self, ranges: List[List[int]]) -> int:
    kMod = 1_000_000_007
    ans = 1
    prevEnd = -1

    for start, end in sorted(ranges):
      if start > prevEnd:
        ans = ans * 2 % kMod
      prevEnd = max(prevEnd, end)

    return ans
