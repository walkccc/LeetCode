class Solution:
  def occurrencesOfElement(
      self,
      nums: list[int],
      queries: list[int],
      x: int,
  ) -> list[int]:
    indices = [i for i, num in enumerate(nums) if num == x]
    return [indices[query - 1] if query <= len(indices) else -1
            for query in queries]
