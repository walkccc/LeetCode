class Solution:
  def numberOfWays(self, n: int, x: int, y: int) -> int:
    MOD = 1_000_000_007

    @functools.lru_cache(None)
    def fact(i: int) -> int:
      return 1 if i <= 1 else i * fact(i - 1) % MOD

    @functools.lru_cache(None)
    def inv(i: int) -> int:
      return pow(i, MOD - 2, MOD)

    @functools.lru_cache(None)
    def nCk(n: int, k: int) -> int:
      return fact(n) * inv(fact(k)) * inv(fact(n - k)) % MOD

    @functools.lru_cache(None)
    def stirling(n: int, k: int) -> int:
      """
      Returns the number of ways to partition a set of n objects into k
      non-empty subsets.

      https://en.wikipedia.org/wiki/Stirling_numbers_of_the_second_kind
      """
      if k == 0 or n < k:
        return 0
      if k == 1 or n == k:
        return 1
      return (k * stirling(n - 1, k) + stirling(n - 1, k - 1)) % MOD

    # 1. Choose `k` stages from `x` stages.
    # 2. Partition `n` performers into `k` stages.
    # 3. Permute `k` stages.
    # 4. Score `k` stages with score in the range [1, y], so y^k ways.
    return sum(nCk(x, k) * stirling(n, k) * fact(k) * pow(y, k, MOD) % MOD
               for k in range(1, min(n, x) + 1)) % MOD
