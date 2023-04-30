class Solution:
  def maxProduct(self, nums: List[int]) -> int:
    ans = nums[0]
    prevMin = nums[0]
    prevMax = nums[0]

    for i in range(1, len(nums)):
      mini = prevMin * nums[i]
      maxi = prevMax * nums[i]
      prevMin = min(nums[i], mini, maxi)
      prevMax = max(nums[i], mini, maxi)
      ans = max(ans, prevMax)

    return ans
