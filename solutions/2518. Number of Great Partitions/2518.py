class Solution:
  def countPartitions(self, nums: list[int], k: int) -> int:
    MOD = 1_000_000_007
    summ = sum(nums)
    ans = pow(2, len(nums), MOD)  # 2^n % MOD
    dp = [1] + [0] * k

    for num in nums:
      for i in range(k, num - 1, -1):
        dp[i] += dp[i - num]
        dp[i] %= MOD

    # Substract the cases that're not satisfied.
    for i in range(k):
      if summ - i < k:  # Both group1 and group2 < k.
        ans -= dp[i]
      else:
        ans -= dp[i] * 2

    return ans % MOD
