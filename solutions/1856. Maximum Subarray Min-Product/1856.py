class Solution:
  def maxSumMinProduct(self, nums: list[int]) -> int:
    ans = 0
    stack = []
    prefix = list(itertools.accumulate(nums, initial=0))

    for i in range(len(nums) + 1):
      while stack and (i == len(nums) or nums[stack[-1]] > nums[i]):
        minVal = nums[stack.pop()]
        summ = prefix[i] - prefix[stack[-1] + 1] if stack else prefix[i]
        ans = max(ans, minVal * summ)
      stack.append(i)

    return ans % int(1e9 + 7)
