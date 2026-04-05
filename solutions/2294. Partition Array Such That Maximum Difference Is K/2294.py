class Solution:
  def partitionArray(self, nums: list[int], k: int) -> int:
    nums.sort()

    ans = 1
    mn = nums[0]

    for i in range(1, len(nums)):
      if mn + k < nums[i]:
        ans += 1
        mn = nums[i]

    return ans
