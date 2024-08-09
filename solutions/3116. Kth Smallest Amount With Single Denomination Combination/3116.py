class Solution:
  def findKthSmallest(self, coins: List[int], k: int) -> int:
    sizeToLcms = self._getSizeToLcms(coins)

    def count(m: int) -> int:
      """Returns the number of denominations <= m."""
      res = 0
      for sz, lcms in enumerate(sizeToLcms):
        for lcm in lcms:
          # Principle of Inclusion-Exclusion (PIE)
          res += m // lcm * pow(-1, sz + 1)
      return res

    return bisect.bisect_left(range(0, k * min(coins)), k,
                              key=lambda m: count(m))

  def _getSizeToLcms(self, coins: List[int]) -> List[List[int]]:
    # Returns the LCMs for each number of combination of coins.
    sizeToLcms = [[] for _ in range(len(coins) + 1)]
    for sz in range(1, len(coins) + 1):
      for combination in itertools.combinations(coins, sz):
        sizeToLcms[sz].append(math.lcm(*combination))
    return sizeToLcms
