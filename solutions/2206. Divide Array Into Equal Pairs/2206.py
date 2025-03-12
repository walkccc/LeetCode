class Solution:
  def divideArray(self, nums: list[int]) -> bool:
    return all(value % 2 == 0 for value in collections.Counter(nums).values())
