class Solution:
  def makeEqual(self, words: list[str]) -> bool:
    return all(c % len(words) == 0
               for c in collections.Counter(''.join(words)).values())
