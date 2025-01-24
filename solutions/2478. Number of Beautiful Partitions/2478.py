class Solution:
  def beautifulPartitions(self, s: str, k: int, minLength: int) -> int:
    def isPrime(c: str) -> bool:
      return c in '2357'

    if not isPrime(s[0]) or isPrime(s[-1]):
      return 0

    kMod = 1_000_000_007

    @lru_cache(None)
    def dp(i: int, k: int) -> int:
      """
      Returns the number of beautiful partitions of s[i..n) with k bars (|)
      left.
      """
      if i <= len(s) and k == 0:
        return 1
      if i >= len(s):
        return 0

      # Don't split between s[i - 1] and s[i].
      ans = dp(i + 1, k) % kMod

      # Split between s[i - 1] and s[i].
      if isPrime(s[i]) and not isPrime(s[i - 1]):
        ans += dp(i + minLength, k - 1)

      return ans % kMod

    return dp(minLength, k - 1)
