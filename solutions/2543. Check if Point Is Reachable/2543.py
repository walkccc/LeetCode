class Solution:
  def isReachable(self, targetX: int, targetY: int) -> bool:
    return math.gcd(targetX, targetY).bit_count() == 1
