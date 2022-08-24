class Solution:
  def minimumTime(self, s: str) -> int:
    n = len(s)
    ans = n
    left = 0  # min time to remove illegal cars so far

    for i, c in enumerate(s):
      left = min(left + (ord(c) - ord('0')) * 2, i + 1)
      ans = min(ans, left + n - 1 - i)

    return ans
