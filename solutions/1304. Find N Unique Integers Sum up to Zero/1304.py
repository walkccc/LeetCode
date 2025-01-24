class Solution:
  def sumZero(self, n: int) -> list[int]:
    return list(range(1 - n, n, 2))
