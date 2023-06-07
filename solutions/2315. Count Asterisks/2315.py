class Solution:
  def countAsterisks(self, s: str) -> int:
    ans = 0
    bars = 0

    for c in s:
      if c == '|':
        bars += 1
      elif c == '*' and bars % 2 == 0:
        ans += 1

    return ans
