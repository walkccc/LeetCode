class Solution:
  def countGoodNumbers(self, n: int) -> int:
    kMod = 1_000_000_007

    def myPow(x: int, n: int) -> int:
      if n == 0:
        return 1
      if n & 1:
        return x * myPow(x, n - 1) % kMod
      return myPow(x * x % kMod, n // 2)

    return myPow(4 * 5, n // 2) * (5 if n & 1 else 1) % kMod
