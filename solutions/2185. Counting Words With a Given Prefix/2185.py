class Solution:
  def prefixCount(self, words: list[str], pref: str) -> int:
    return sum(word.startswith(pref) for word in words)
