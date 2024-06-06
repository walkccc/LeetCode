class Solution:
  def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
    return sum(all(c in allowed for c in word)
               for word in words)
