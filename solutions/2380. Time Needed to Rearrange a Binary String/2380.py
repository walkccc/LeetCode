class Solution:
  def secondsToRemoveOccurrences(self, s: str) -> int:
    ans = 0
    zeros = 0

    for c in s:
      if c == '0':
        zeros += 1
      elif zeros:  # C == '1'
        ans = max(ans + 1, zeros)

    return ans
