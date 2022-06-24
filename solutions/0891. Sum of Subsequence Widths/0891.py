class Solution:
  def sumSubseqWidths(self, nums: List[int]) -> int:
    kMod = int(1e9) + 7
    n = len(nums)
    ans = 0
    exp = 1

    nums.sort()

    for i in range(n):
      ans += (nums[i] - nums[n - i - 1]) * exp
      ans %= kMod
      exp = exp * 2 % kMod

    return ans
