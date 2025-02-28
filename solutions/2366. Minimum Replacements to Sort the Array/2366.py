class Solution:
  def minimumReplacement(self, nums: list[int]) -> int:
    ans = 0
    mx = nums[-1]

    for i in range(len(nums) - 2, -1, -1):
      ops = (nums[i] - 1) // mx
      ans += ops
      mx = nums[i] // (ops + 1)

    return ans
