class Solution:
  def smallestPalindrome(self, s: str) -> str:
    n = len(s)
    sortedHalf = sorted(s[:n // 2])
    return ''.join(sortedHalf +
                   ([s[n // 2]] if n % 2 else []) +
                   sortedHalf[::-1])
