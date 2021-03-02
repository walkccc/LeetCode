class Solution:
  def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
    def dist(p1: List[int], p2: List[int]) -> int:
      return (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2

    distSet = set()
    points = [p1, p2, p3, p4]

    for i in range(4):
      for j in range(i + 1, 4):
        distSet.add(dist(points[i], points[j]))

    return 0 not in distSet and len(distSet) == 2
