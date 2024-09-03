class Solution:
  def maxCoins(self, piles: list[int]) -> int:
    return sum(sorted(piles)[len(piles) // 3::2])
