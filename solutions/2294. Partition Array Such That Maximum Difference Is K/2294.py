class Solution:
  def partitionArray(self, nums: List[int], k: int) -> int:
    nums.sort()

    ans = 1
    min = nums[0]

    for i in range(1, len(nums)):
      if min + k < nums[i]:
        ans += 1
        min = nums[i]

    return ans
