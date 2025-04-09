class Solution:
  def smallestNumber(self, n: int, t: int) -> int:
    return next(num for num in range(n, n + 10)
                if self._getDigitProd(num) % t == 0)

  def _getDigitProd(self, num: int) -> int:
    digitProd = 1
    while num > 0:
      digitProd *= num % 10
      num //= 10
    return digitProd
