class Solution:
  def findClosest(self, x: int, y: int, z: int) -> int:
    xz = abs(x - z)
    yz = abs(y - z)
    if xz == yz:
      return 0
    return 1 if xz < yz else 2
