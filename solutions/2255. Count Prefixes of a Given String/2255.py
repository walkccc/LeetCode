class Solution:
  def countPrefixes(self, words: list[str], s: str) -> int:
    return sum(map(s.startswith, words))
