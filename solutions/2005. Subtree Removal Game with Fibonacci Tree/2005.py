class Solution:
  def findGameWinner(self, n: int) -> bool:
    return n % 6 != 1
