class Solution:
  def subsequencePairCount(self, nums: list[int]) -> int:
    MOD = 1_000_000_007
    maxNum = max(nums)
    # dp[i][x][y] := number of disjoint pairs `seq1` and `seq2` of
    # nums[0..i - 1], where GCD(seq1) == x and GCD(seq2) == y
    dp = [[[0] * (maxNum + 1)
          for _ in range(maxNum + 1)]
          for _ in range(len(nums) + 1)]
    dp[0][0][0] = 1

    for i, num in enumerate(nums):
      for x in range(maxNum + 1):
        for y in range(maxNum + 1):
          # 1. Skip nums[i].
          dp[i + 1][x][y] += dp[i][x][y]
          dp[i + 1][x][y] %= MOD
          # 2. Pick nums[i] in the first subsequence.
          newX = math.gcd(x, num)
          dp[i + 1][newX][y] += dp[i][x][y]
          dp[i + 1][newX][y] %= MOD
          # 3. Pick nums[i] in the second subsequence.
          newY = math.gcd(y, num)
          dp[i + 1][x][newY] += dp[i][x][y]
          dp[i + 1][x][newY] %= MOD

    return sum(dp[-1][g][g]
               for g in range(1, maxNum + 1)) % MOD
