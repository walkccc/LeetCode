class Solution:
  def countLatticePoints(self, circles: list[list[int]]) -> int:
    points = set()

    # dx := relative to x
    # dy := relative to y
    # So, dx^2 + dy^2 = r^2.
    for x, y, r in circles:
      for dx in range(-r, r + 1):
        yMax = int((r**2 - dx**2)**0.5)
        for dy in range(-yMax, yMax + 1):
          points.add((x + dx, y + dy))

    return len(points)
