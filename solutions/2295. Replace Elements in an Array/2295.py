class Solution:
  def arrayChange(
      self,
      nums: list[int],
      operations: list[list[int]],
  ) -> list[int]:
    numToIndex = {num: i for i, num in enumerate(nums)}

    for original, replaced in operations:
      index = numToIndex[original]
      nums[index] = replaced
      del numToIndex[original]
      numToIndex[replaced] = index

    return nums
