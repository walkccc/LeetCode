class Solution:
  def minimumTime(self, s: str) -> int:
    n = len(s)
    ans = n
    left = 0  # the minimum time to remove the illegal cars so far

    for i, c in enumerate(s):
      left = min(left + int(c) * 2, i + 1)
      ans = min(ans, left + n - 1 - i)

    return ans
