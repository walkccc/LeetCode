class Solution:
  def titleToNumber(self, s: str) -> int:
    ans = 0

    for c in s:
      ans = ans * 26 + ord(c) - ord('@')

    return ans
