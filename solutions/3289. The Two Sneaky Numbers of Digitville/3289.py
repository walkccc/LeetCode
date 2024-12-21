class Solution:
  def getSneakyNumbers(self, nums: list[int]) -> list[int]:
    return [num for num, freq in collections.Counter(nums).items()
            if freq == 2]
