class Solution:
  def countOfArrays(self, n: int, m: int, k: int) -> int:
    MOD = 10**9 + 7
    even = m // 2  # the number of even numbers in [1, m]
    odd = m - even  # the number of odd numbers in [1, m]
    # dp[j][0/1] := the number of arrays of length so far i with j consecutive
    # even number pairs ending in an even number (0) or an odd number (1)
    dp = [[0] * 2 for _ in range(k + 1)]

    # Base case: arrays of length 1
    # For an array of length 1, we can't have any even number pairs yet.
    dp[0][0] = even
    dp[0][1] = odd

    for _ in range(2, n + 1):
      newDp = [[0] * 2 for _ in range(k + 1)]
      for j in range(k + 1):
        # 1. Appending an even number to an array ending in an even number
        #    creates a new consecutive even number pair.
        # 2. Appending an even number to an array ending in an odd number.
        newDp[j][0] = ((dp[j - 1][0] if j > 0 else 0) * even +
                       dp[j][1] * even) % MOD
        # 3. Appending an odd number to an array.
        newDp[j][1] = sum(dp[j]) * odd % MOD
      dp = newDp

    return sum(dp[k]) % MOD
