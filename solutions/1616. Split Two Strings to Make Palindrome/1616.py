class Solution:
  def checkPalindromeFormation(self, a: str, b: str) -> bool:
    return self._check(a, b) or self._check(b, a)

  def _check(self, a: str, b: str) -> bool:
    i, j = 0, len(a) - 1
    while i < j:
      if a[i] != b[j]:
        # a[0:i] + a[i..j] + b[j + 1:] or
        # a[0:i] + b[i..j] + b[j + 1:]
        return self._isPalindrome(a, i, j) or self._isPalindrome(b, i, j)
      i += 1
      j -= 1
    return True

  def _isPalindrome(self, s: str, i: int, j: int) -> bool:
    while i < j:
      if s[i] != s[j]:
        return False
      i += 1
      j -= 1
    return True
