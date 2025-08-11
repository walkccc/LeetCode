class Solution:
  def canDistribute(self, nums: list[int], quantity: list[int]) -> bool:
    freqs = list(collections.Counter(nums).values())
    # validDistribution[i][j] := True if it's possible to distribute the i-th
    # freq into a subset of quantity represented by the bitmask j
    validDistribution = self._getValidDistribution(freqs, quantity)
    n = len(freqs)
    m = len(quantity)
    maxMask = 1 << m
    # dp[i][j] := true if it's possible to distribute freqs[i..n), where j is
    # the bitmask of the selected quantity
    dp = [[False] * maxMask for _ in range(n + 1)]
    dp[n][maxMask - 1] = True

    for i in range(n - 1, -1, -1):
      for mask in range(maxMask):
        dp[i][mask] = dp[i + 1][mask]
        availableMask = ~mask & (maxMask - 1)
        submask = availableMask
        while submask > 0:
          if validDistribution[i][submask]:
            dp[i][mask] = dp[i][mask] or dp[i + 1][mask | submask]
          submask = (submask - 1) & availableMask

    return dp[0][0]

  def _getValidDistribution(self, freqs: list[int],
                            quantity: list[int]) -> list[list[bool]]:
    maxMask = 1 << len(quantity)
    validDistribution = [[False] * maxMask for _ in range(len(freqs))]
    for i, freq in enumerate(freqs):
      for mask in range(maxMask):
        if freq >= self._getQuantitySum(quantity, mask):
          validDistribution[i][mask] = True
    return validDistribution

  def _getQuantitySum(self, quantity: list[int], mask: int) -> int:
    """Returns the sum of the selected quantity represented by `mask`."""
    return sum(q for i, q in enumerate(quantity) if mask >> i & 1)
