class Solution:
  def canAliceWin(self, n: int) -> bool:
    for stones in range(10, -1, -1):
      if stones > n:
        return stones % 2 == 1
      n -= stones
