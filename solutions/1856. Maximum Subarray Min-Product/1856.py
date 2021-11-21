class Solution:
  def maxSumMinProduct(self, nums: List[int]) -> int:
    ans = 0
    stack = []
    prefix = [0] * (len(nums) + 1)

    for i, num in enumerate(nums):
      prefix[i + 1] = prefix[i] + num

    for i in range(len(nums) + 1):
      while stack and (i == len(nums) or nums[stack[-1]] > nums[i]):
        minVal = nums[stack.pop()]
        sum = prefix[i] - prefix[stack[-1] + 1] if stack else prefix[i]
        ans = max(ans, minVal * sum)
      stack.append(i)

    return ans % int(1e9 + 7)
