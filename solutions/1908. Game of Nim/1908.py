class Solution:
  def nimGame(self, piles: List[int]) -> bool:
    return functools.reduce(operator.xor, piles) > 0
