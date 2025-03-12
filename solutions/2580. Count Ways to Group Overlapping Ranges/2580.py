class Solution:
  def countWays(self, ranges: list[list[int]]) -> int:
    MOD = 1_000_000_007
    ans = 1
    prevEnd = -1

    for start, end in sorted(ranges):
      if start > prevEnd:
        ans = ans * 2 % MOD
      prevEnd = max(prevEnd, end)

    return ans
