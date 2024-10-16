class Solution:
  def percentageLetter(self, s: str, letter: str) -> int:
    return 100 * s.count(letter) // len(s)
