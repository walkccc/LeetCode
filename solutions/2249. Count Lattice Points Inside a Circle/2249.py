class Solution:
  def countLatticePoints(self, circles: List[List[int]]) -> int:
    return sum(any((xc - x)**2 + (yc - y)**2 <= r**2 for xc, yc, r in circles)
               for x in range(201)
               for y in range(201))
