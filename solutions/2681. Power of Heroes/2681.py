class Solution:
  def sumOfPower(self, nums: list[int]) -> int:
    MOD = 1_000_000_007
    ans = 0
    summ = 0

    for num in sorted(nums):
      ans += (num + summ) * num**2
      ans %= MOD
      summ = (summ * 2 + num) % MOD

    return ans
