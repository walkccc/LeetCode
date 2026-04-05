class Solution:
  def countBalancedPermutations(self, num: str) -> int:
    nums = list(map(int, num))
    summ = sum(nums)
    if summ % 2 == 1:
      return 0

    nums.sort(reverse=True)

    @functools.lru_cache(None)
    def dp(even: int, odd: int, evenBalance: int) -> int:
      """
      Returns the number of permutations where there are `even` even indices
      left, `odd` odd indices left, and `evenBalance` is the target sum of the
      remaining numbers to be placed in even indices.
      """
      if evenBalance < 0:
        return 0
      if even == 0:
        return (evenBalance == 0) * math.factorial(odd)
      if odd == 0:
        return (sum(nums[-(even + odd):]) == evenBalance) * math.factorial(even)
      return (dp(even - 1, odd, evenBalance - nums[-(odd + even)]) * even +
              dp(even, odd - 1, evenBalance) * odd)

    MOD = 1_000_000_007
    perm = functools.reduce(lambda x, y: x * math.factorial(y),
                            collections.Counter(nums).values(), 1)
    return (dp(even=(len(nums) + 1) // 2,
               odd=len(nums) // 2,
               evenBalance=summ // 2) // perm) % MOD
