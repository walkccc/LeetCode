class Solution:
  def getSum(self, a: int, b: int) -> int:
    mask = 0xFFFFFFFF
    kMax = 2000

    while b:
      a, b = (a ^ b) & mask, ((a & b) << 1) & mask

    return a if a < kMax else ~(a ^ mask)
