class Solution:
  def findIndices(
      self,
      nums: list[int],
      indexDifference: int,
      valueDifference: int,
  ) -> list[int]:
    # nums[minIndex] := the minimum number with enough index different from the
    # current number
    minIndex = 0
    # nums[maxIndex] := the maximum number with enough index different from the
    # current number
    maxIndex = 0

    for i in range(indexDifference, len(nums)):
      if nums[i - indexDifference] < nums[minIndex]:
        minIndex = i - indexDifference
      if nums[i - indexDifference] > nums[maxIndex]:
        maxIndex = i - indexDifference
      if nums[i] - nums[minIndex] >= valueDifference:
        return [i, minIndex]
      if nums[maxIndex] - nums[i] >= valueDifference:
        return [i, maxIndex]

    return [-1, -1]
