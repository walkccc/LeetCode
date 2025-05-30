class Solution:
  def getSum(self, a: int, b: int) -> int:
    mask = 0xFFFFFFFF
    MAX = 2000

    while b != 0:
      a, b = (a ^ b) & mask, ((a & b) << 1) & mask

    return a if a < MAX else ~(a ^ mask)
