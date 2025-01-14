class Solution:
  # Same as 2970. Count the Number of Incremovable Subarrays I
  def incremovableSubarrayCount(self, nums: list[int]) -> int:
    n = len(nums)
    startIndex = self._getStartIndexOfSuffix(nums)
    # If the complete array is strictly increasing, the total number of ways we
    # can remove elements equals the total number of possible subarrays.
    if startIndex == 0:
      return n * (n + 1) // 2

    # The valid removals starting from nums[0] include nums[0..startIndex - 1],
    # nums[0..startIndex], ..., nums[0..n).
    ans = n - startIndex + 1

    # Enumerate each prefix subarray that is strictly increasing.
    for i in range(startIndex):
      if i > 0 and nums[i] <= nums[i - 1]:
        break
      # Since nums[0..i] is strictly increasing, find the first index j in
      # nums[startIndex..n) such that nums[j] > nums[i]. The valid removals
      # will then be nums[i + 1..j - 1], nums[i + 1..j], ..., nums[i + 1..n).
      ans += n - bisect.bisect_right(nums, nums[i], startIndex) + 1

    return ans

  def _getStartIndexOfSuffix(self, nums: list[int]) -> int:
    for i in range(len(nums) - 2, -1, -1):
      if nums[i] >= nums[i + 1]:
        return i + 1
    return 0
