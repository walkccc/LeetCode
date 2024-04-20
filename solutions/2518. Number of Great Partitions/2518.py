class Solution:
  def countPartitions(self, nums: List[int], k: int) -> int:
    kMod = 1_000_000_007
    summ = sum(nums)
    ans = pow(2, len(nums), kMod)  # 2^n % kMod
    dp = [1] + [0] * k

    for num in nums:
      for i in range(k, num - 1, -1):
        dp[i] += dp[i - num]
        dp[i] %= kMod

    # Substract the cases that're not satisfied.
    for i in range(k):
      if summ - i < k:  # Both group1 and group2 < k.
        ans -= dp[i]
      else:
        ans -= dp[i] * 2

    return ans % kMod
