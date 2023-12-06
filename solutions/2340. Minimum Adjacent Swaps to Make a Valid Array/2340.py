class Solution:
  def minimumSwaps(self, nums: List[int]) -> int:
    minIndex = self._getLeftmostMinIndex(nums)
    maxIndex = self._getRightmostMaxIndex(nums)
    swaps = minIndex + (len(nums) - 1 - maxIndex)
    return swaps if minIndex <= maxIndex else swaps - 1

  def _getLeftmostMinIndex(self, nums: List[int]) -> int:
    min = nums[0]
    minIndex = 0
    for i in range(1, len(nums)):
      if nums[i] < min:
        min = nums[i]
        minIndex = i
    return minIndex

  def _getRightmostMaxIndex(self, nums: List[int]) -> int:
    max = nums[-1]
    maxIndex = len(nums) - 1
    for i in range(len(nums) - 2, -1, -1):
      if nums[i] > max:
        max = nums[i]
        maxIndex = i
    return maxIndex
