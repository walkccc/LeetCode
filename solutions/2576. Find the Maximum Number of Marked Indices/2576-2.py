class Solution:
  def maxNumOfMarkedIndices(self, nums: list[int]) -> int:
    nums.sort()

    i = 0
    for j in range(len(nums) // 2, len(nums)):
      if 2 * nums[i] <= nums[j]:
        i += 1
        if i == len(nums) // 2:
          break

    return i * 2
