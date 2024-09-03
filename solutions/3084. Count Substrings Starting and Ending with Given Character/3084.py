class Solution:
  def countSubstrings(self, s: str, c: str) -> int:
    freq = s.count(c)
    return freq * (freq + 1) // 2
