class Solution:
  def distributeCandies(self, candies: list[int]) -> int:
    return min(len(candies) // 2, len(set(candies)))
