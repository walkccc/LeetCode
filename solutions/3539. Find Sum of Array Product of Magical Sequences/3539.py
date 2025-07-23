class Solution:
  def magicalSum(self, m: int, k: int, nums: list[int]) -> int:
    MOD = 1_000_000_007

    @functools.lru_cache(None)
    def dp(m: int, k: int, i: int, carry: int) -> int:
      """
      Returns the number of magical sequences of length `k` that can be formed
      from the first `i` numbers in `nums` with at most `m` elements.
      """
      if m < 0 or k < 0 or (m + carry.bit_count() < k):
        return 0
      if m == 0:
        return int(k == carry.bit_count())
      if i == len(nums):
        return 0
      res = 0
      for count in range(m + 1):
        contribution = math.comb(m, count) * pow(nums[i], count, MOD) % MOD
        newCarry = carry + count
        res += dp(m - count, k - (newCarry % 2),
                  i + 1, newCarry // 2) * contribution
        res %= MOD
      return res

    return dp(m, k, 0, 0)
