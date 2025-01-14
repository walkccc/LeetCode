class Solution:
  def twoSum(self, nums: list[int], target: int) -> list[int]:
    numToIndex = {}

    for i, num in enumerate(nums):
      if target - num in numToIndex:
        return numToIndex[target - num], i
      numToIndex[num] = i
