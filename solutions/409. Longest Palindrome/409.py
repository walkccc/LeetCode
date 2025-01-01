class Solution:
  def longestPalindrome(self, s: str) -> int:
    ans = 0
    count = collections.Counter(s)

    for c in count.values():
      ans += c if c % 2 == 0 else c - 1

    hasOddCount = any(c % 2 == 1 for c in count.values())
    return ans + hasOddCount
