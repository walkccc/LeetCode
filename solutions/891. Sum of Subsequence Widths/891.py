class Solution:
  def sumSubseqWidths(self, nums: list[int]) -> int:
    MOD = 1_000_000_007
    n = len(nums)
    ans = 0
    exp = 1

    nums.sort()

    for i in range(n):
      ans += (nums[i] - nums[n - 1 - i]) * exp
      ans %= MOD
      exp = exp * 2 % MOD

    return ans
