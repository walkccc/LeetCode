class Solution:
  def findOcurrences(self, text: str, first: str, second: str) -> list[str]:
    words = text.split()
    return [c for a, b, c in zip(words, words[1:], words[2:]) if a == first and b == second]
