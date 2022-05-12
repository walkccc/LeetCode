class Solution:
  def visiblePoints(self, points: List[List[int]], angle: int, location: List[int]) -> int:
    posX, posY = location
    maxVisible = 0
    same = 0
    A = []

    for x, y in points:
      if x == posX and y == posY:
        same += 1
      else:
        A.append(math.atan2(y - posY, x - posX))

    A.sort()
    A = A + [a + 2.0 * math.pi for a in A]

    angleInRadians = math.pi * (angle / 180)

    l = 0
    for r in range(len(A)):
      while A[r] - A[l] > angleInRadians:
        l += 1
      maxVisible = max(maxVisible, r - l + 1)

    return maxVisible + same
