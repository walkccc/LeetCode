class Solution:
  def canPermutePalindrome(self, s: str) -> bool:
    seen = set()

    for c in s:
      if c in seen:
        seen.remove(c)
      else:
        seen.add(c)

    return len(seen) <= 1
