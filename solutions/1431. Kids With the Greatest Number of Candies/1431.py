class Solution:
  def kidsWithCandies(
      self,
      candies: list[int],
      extraCandies: int,
  ) -> list[bool]:
    maxCandy = max(candies)
    return [candy + extraCandies >= maxCandy for candy in candies]
