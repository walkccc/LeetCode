class Solution:
  def longestPalindrome(self, s: str) -> str:
    if not s:
      return ''

    # (start, end) indices of the longest palindrome in s
    indices = [0, 0]

    def extend(s: str, i: int, j: int) -> Tuple[int, int]:
      """
      Returns the (start, end) indices of the longest palindrome extended from
      the substring s[i..j].
      """
      while i >= 0 and j < len(s):
        if s[i] != s[j]:
          break
        i -= 1
        j += 1
      return i + 1, j - 1

    for i in range(len(s)):
      l1, r1 = extend(s, i, i)
      if r1 - l1 > indices[1] - indices[0]:
        indices = l1, r1
      if i + 1 < len(s) and s[i] == s[i + 1]:
        l2, r2 = extend(s, i, i + 1)
        if r2 - l2 > indices[1] - indices[0]:
          indices = l2, r2

    return s[indices[0]:indices[1] + 1]
