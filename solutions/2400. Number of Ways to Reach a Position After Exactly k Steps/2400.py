class Solution:
  def numberOfWays(self, startPos: int, endPos: int, k: int) -> int:
    # leftStep + rightStep = k
    # rightStep - leftStep = endPos - startPos
    #        2 * rightStep = k + endPos - startPos
    #            rightStep = (k + endPos - startPos) // 2
    val = k + endPos - startPos
    if val < 0 or val % 2 == 1:
      return 0
    rightStep = val // 2
    leftStep = k - rightStep
    if leftStep < 0:
      return 0
    return self._nCk(leftStep + rightStep, min(leftStep, rightStep))

  # C(n, k) = C(n - 1, k) + C(n - 1, k - 1)
  def _nCk(self, n: int, k: int) -> int:
    kMod = 1_000_000_007
    # dp[i] := C(n so far, i)
    dp = [1] + [0] * k

    for _ in range(n):  # Calculate n times.
      for j in range(k, 0, -1):
        dp[j] += dp[j - 1]
        dp[j] %= kMod

    return dp[k]
