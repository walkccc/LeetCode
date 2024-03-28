class Solution:
  def findTheLongestBalancedSubstring(self, s: str) -> int:
    ans = 0
    zeros = 0
    ones = 0

    for c in s:
      if c == '0':
        zeros = 1 if ones > 0 else zeros + 1
        ones = 0
      else:  # c == '1'
        ones += 1
      if zeros >= ones:
        ans = max(ans, ones)

    return ans * 2
