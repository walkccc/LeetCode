class Solution:
  def countGoodNumbers(self, n: int) -> int:
    MOD = 1_000_000_007

    def modPow(x: int, n: int) -> int:
      if n == 0:
        return 1
      if n % 2 == 1:
        return x * modPow(x, n - 1) % MOD
      return modPow(x * x % MOD, n // 2)

    return modPow(4 * 5, n // 2) * (1 if n % 2 == 0 else 5) % MOD
