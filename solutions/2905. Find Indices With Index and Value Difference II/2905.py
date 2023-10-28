class Solution:
  def findIndices(self, nums: List[int], indexDifference: int, valueDifference: int) -> List[int]:
    # nums[minIndex] := min num with enough index diff from current num
    minIndex = 0
    # nums[maxIndex] := max num with enough index diff from current num
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
