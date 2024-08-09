class Solution:
  def winnerOfGame(self, colors: str) -> bool:
    countAAA = 0
    countBBB = 0

    for a, b, c in zip(colors, colors[1:], colors[2:]):
      if 'A' == a == b == c:
        countAAA += 1
      elif 'B' == a == b == c:
        countBBB += 1

    return countAAA > countBBB
