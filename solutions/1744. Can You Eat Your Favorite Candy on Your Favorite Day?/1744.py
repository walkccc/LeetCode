class Solution:
  def canEat(
      self,
      candiesCount: list[int],
      queries: list[list[int]]
  ) -> list[bool]:
    prefix = list(itertools.accumulate(candiesCount, initial=0))
    return [prefix[t] // c <= d < prefix[t + 1] for t, d, c in queries]
