class Solution:
  def appealSum(self, s: str) -> int:
    ans = 0
    lastOccurrence = [-1] * 26

    for i, c in enumerate(s):
      ans += (i - lastOccurrence[ord(c) - ord('a')]) * (len(s) - i)
      lastOccurrence[ord(c) - ord('a')] = i

    return ans
