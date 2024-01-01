class Solution:
  def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
    maxCandy = max(candies)
    return [candy + extraCandies >= maxCandy for candy in candies]
