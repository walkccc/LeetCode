class Solution:
  def makePalindrome(self, s: str) -> bool:
    change = 0
    l = 0
    r = len(s) - 1

    while l < r:
      if s[l] != s[r]:
        change += 1
        if change > 2:
          return False
      l += 1
      r -= 1

    return True
