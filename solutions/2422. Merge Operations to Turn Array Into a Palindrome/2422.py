class Solution:
  def minimumOperations(self, nums: list[int]) -> int:
    ans = 0
    l = 0
    r = len(nums) - 1
    leftSum = nums[0]
    rightSum = nums[-1]

    while l < r:
      if leftSum < rightSum:
        l += 1
        leftSum += nums[l]
        ans += 1
      elif leftSum > rightSum:
        r -= 1
        rightSum += nums[r]
        ans += 1
      else:  # leftSum == rightSum
        l += 1
        r -= 1
        leftSum = nums[l]
        rightSum = nums[r]

    return ans
