class Solution:
  def appealSum(self, s: str) -> int:
    ans = 0
    dp = 0  # # Of appeal of ending at current index
    lastOccurrence = [-1] * 26

    for i, c in enumerate(s):
      dp += i - lastOccurrence[ord(c) - ord('a')]
      ans += dp
      lastOccurrence[ord(c) - ord('a')] = i

    return ans
