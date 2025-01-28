class Solution:
  def validPalindrome(self, s: str) -> bool:
    def validPalindrome(l: int, r: int) -> bool:
      return all(s[i] == s[r - i + l] for i in range(l, (l + r) // 2 + 1))

    n = len(s)

    for i in range(n // 2):
      if s[i] != s[~i]:
        return validPalindrome(i + 1, n - 1 - i) or validPalindrome(i, n - 2 - i)

    return True
