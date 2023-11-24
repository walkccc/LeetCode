class Solution:
  def minimumSteps(self, s: str) -> int:
    ans = 0
    ones = 0

    for c in s:
      if c == '1':
        ones += 1
      else:  # Move `ones` to the front of current '0'.
        ans += ones

    return ans
