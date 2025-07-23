class Solution:
  def abbreviateProduct(self, left: int, right: int) -> str:
    prod = 1.0
    suf = 1
    countDigits = 0
    countZeros = 0

    for num in range(left, right + 1):
      prod *= num
      while prod >= 1.0:
        prod /= 10
        countDigits += 1
      suf *= num
      while suf % 10 == 0:
        suf //= 10
        countZeros += 1
      if suf > 10**8:
        suf %= 10**8

    if countDigits - countZeros <= 10:
      tens = 10**(countDigits - countZeros)
      return str(int(prod * tens + 0.5)) + 'e' + str(countZeros)

    pre = str(int(prod * 10 ** 5))
    suf = str(suf)[-5:]
    return pre + '...' + suf + 'e' + str(countZeros)
