class Solution:
  def minimumReplacement(self, nums: List[int]) -> int:
    ans = 0

    max = nums[-1]
    for i in range(len(nums) - 2, -1, -1):
      ops = (nums[i] - 1) // max
      ans += ops
      max = nums[i] // (ops + 1)

    return ans
