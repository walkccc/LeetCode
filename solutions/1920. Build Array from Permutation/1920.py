class Solution:
  def buildArray(self, nums: list[int]) -> list[int]:
    n = len(nums)

    for i, num in enumerate(nums):
      nums[i] += n * (nums[num] % n)

    for i in range(n):
      nums[i] //= n

    return nums
