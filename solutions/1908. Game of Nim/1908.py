class Solution:
  def nimGame(self, piles: list[int]) -> bool:
    return functools.reduce(operator.xor, piles) > 0
