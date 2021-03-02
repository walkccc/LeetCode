from fractions import gcd


class Solution:
  def canMeasureWater(self, x: int, y: int, z: int) -> bool:
    return z == 0 or x + y >= z and z % gcd(x, y) == 0
