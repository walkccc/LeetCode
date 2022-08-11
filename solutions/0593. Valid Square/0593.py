class Solution:
  def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
    def dist(p1: List[int], p2: List[int]) -> int:
      return (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2

    distSet = set([dist(*pair)
                   for pair in list(itertools.combinations([p1, p2, p3, p4], 2))])

    return 0 not in distSet and len(distSet) == 2
