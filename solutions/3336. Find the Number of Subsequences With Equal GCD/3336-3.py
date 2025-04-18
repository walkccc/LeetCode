class Solution:
  def subsequencePairCount(self, nums: list[int]) -> int:
    MOD = 1_000_000_007
    maxNum = max(nums)
    # dp[x][y] := number of disjoint pairs `seq1` and `seq2` of
    # nums so far, where GCD(seq1) == x and GCD(seq2) == y
    dp = [[0] * (maxNum + 1) for _ in range(maxNum + 1)]
    dp[0][0] = 1

    for num in nums:
      newDp = [[0] * (maxNum + 1) for _ in range(maxNum + 1)]
      for x in range(maxNum + 1):
        for y in range(maxNum + 1):
          # 1. Skip `num`.
          newDp[x][y] += dp[x][y]
          newDp[x][y] %= MOD
          # 2. Pick `num` in the first subsequence.
          newX = math.gcd(x, num)
          newDp[newX][y] += dp[x][y]
          newDp[newX][y] %= MOD
          # 3. Pick `num` in the second subsequence.
          newY = math.gcd(y, num)
          newDp[x][newY] += dp[x][y]
          newDp[x][newY] %= MOD
      dp = newDp

    return sum(dp[g][g]
               for g in range(1, maxNum + 1)) % MOD
