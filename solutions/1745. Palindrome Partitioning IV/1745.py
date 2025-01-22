class Solution:
  def checkPartitioning(self, s: str) -> bool:
    @functools.lru_cache(None)
    def isPalindrome(i: int, j: int) -> bool:
      """Returns True if s[i..j] is a palindrome."""
      if i > j:
        return True
      if s[i] == s[j]:
        return isPalindrome(i + 1, j - 1)
      return False

    n = len(s)
    return any(isPalindrome(0, i) and
               isPalindrome(i + 1, j) and
               isPalindrome(j + 1, n - 1)
               for i in range(n)
               for j in range(i + 1, n - 1))
