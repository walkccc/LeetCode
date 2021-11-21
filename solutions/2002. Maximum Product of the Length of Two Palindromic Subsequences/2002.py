class Solution:
  def maxProduct(self, s: str) -> int:
    self.ans = 0

    def isPalindrome(s: str) -> bool:
      i = 0
      j = len(s) - 1
      while i < j:
        if s[i] != s[j]:
          return False
        i += 1
        j -= 1
      return True

    @lru_cache(None)
    def dfs(i: int, s1: str, s2: str) -> None:
      if i == len(s):
        if isPalindrome(s1) and isPalindrome(s2):
          self.ans = max(self.ans, len(s1) * len(s2))
        return

      dfs(i + 1, s1 + s[i], s2)
      dfs(i + 1, s1, s2 + s[i])
      dfs(i + 1, s1, s2)

    dfs(0, '', '')

    return self.ans
