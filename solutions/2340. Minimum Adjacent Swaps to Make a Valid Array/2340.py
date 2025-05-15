class Solution:
  def minimumSwaps(self, nums: list[int]) -> int:
    minIndex = self._getLeftmostMinIndex(nums)
    maxIndex = self._getRightmostMaxIndex(nums)
    swaps = minIndex + (len(nums) - 1 - maxIndex)
    return swaps if minIndex <= maxIndex else swaps - 1

  def _getLeftmostMinIndex(self, nums: list[int]) -> int:
    mn = nums[0]
    minIndex = 0
    for i in range(1, len(nums)):
      if nums[i] < mn:
        mn = nums[i]
        minIndex = i
    return minIndex

  def _getRightmostMaxIndex(self, nums: list[int]) -> int:
    mx = nums[-1]
    maxIndex = len(nums) - 1
    for i in range(len(nums) - 2, -1, -1):
      if nums[i] > mx:
        mx = nums[i]
        maxIndex = i
    return maxIndex
