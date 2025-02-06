class Solution:
  def maxScore(self, s: str) -> int:
    ans = 0
    zeros = 0
    ones = s.count('1')

    for i in range(len(s) - 1):
      if s[i] == '0':
        zeros += 1
      else:
        ones -= 1
      ans = max(ans, zeros + ones)

    return ans
