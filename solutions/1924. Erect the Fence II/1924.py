from dataclasses import dataclass


@dataclass(frozen=True)
class Point:
  x: float
  y: float


@dataclass(frozen=True)
class Disk:
  center: Point
  radius: float


class Solution:
  def outerTrees(self, trees: list[list[int]]) -> list[float]:
    points = [Point(x, y) for x, y in trees]
    disk = self._welzl(points, 0, [])
    return [disk.center.x, disk.center.y, disk.radius]

  def _welzl(
      self,
      points: list[Point],
      i: int,
      planePoints: list[Point],
  ) -> Disk:
    """Returns the smallest disk that encloses points[i..n).

    https://en.wikipedia.org/wiki/Smallest-disk_problem#Welzl's_algorithm
    """
    if i == len(points) or len(planePoints) == 3:
      return self._trivial(planePoints)
    disk = self._welzl(points, i + 1, planePoints)
    if self._inside(disk, points[i]):
      return disk
    return self._welzl(points, i + 1, planePoints + [points[i]])

  def _trivial(self, planePoints: list[Point]) -> Disk:
    """Returns the smallest disk that encloses `planePoints`."""
    if len(planePoints) == 0:
      return Disk(Point(0, 0), 0)
    if len(planePoints) == 1:
      return Disk(Point(planePoints[0].x, planePoints[0].y), 0)
    if len(planePoints) == 2:
      return self._getDisk(planePoints[0], planePoints[1])

    disk01 = self._getDisk(planePoints[0], planePoints[1])
    if self._inside(disk01, planePoints[2]):
      return disk01

    disk02 = self._getDisk(planePoints[0], planePoints[2])
    if self._inside(disk02, planePoints[1]):
      return disk02

    disk12 = self._getDisk(planePoints[1], planePoints[2])
    if self._inside(disk12, planePoints[0]):
      return disk12

    return self._getDiskFromThree(
        planePoints[0],
        planePoints[1],
        planePoints[2])

  def _getDisk(self, A: Point, B: Point) -> Disk:
    """Returns the smallest disk that encloses the points A and B."""
    x = (A.x + B.x) / 2
    y = (A.y + B.y) / 2
    return Disk(Point(x, y), self._distance(A, B) / 2)

  def _getDiskFromThree(self, A: Point, B: Point, C: Point) -> Disk:
    """Returns the smallest disk that encloses the points A, B, and C."""
    # Calculate midpoints.
    mAB = Point((A.x + B.x) / 2, (A.y + B.y) / 2)
    mBC = Point((B.x + C.x) / 2, (B.y + C.y) / 2)

    # Calculate the slopes and the perpendicular slopes.
    slopeAB = math.inf if B.x == A.x else (B.y - A.y) / (B.x - A.x)
    slopeBC = math.inf if C.x == B.x else (C.y - B.y) / (C.x - B.x)
    perpSlopeAB = math.inf if slopeAB == 0 else -1 / slopeAB
    perpSlopeBC = math.inf if slopeBC == 0 else -1 / slopeBC

    # Calculate the center.
    x = (perpSlopeBC * mBC.x - perpSlopeAB * mAB.x +
         mAB.y - mBC.y) / (perpSlopeBC - perpSlopeAB)
    y = perpSlopeAB * (x - mAB.x) + mAB.y
    center = Point(x, y)
    return Disk(center, self._distance(center, A))

  def _inside(self, disk: Disk, point: Point) -> bool:
    """Returns True if the point is inside the disk."""
    return disk.radius > 0 and self._distance(disk.center, point) <= disk.radius

  def _distance(self, A: Point, B: Point) -> float:
    dx = A.x - B.x
    dy = A.y - B.y
    return math.sqrt(dx**2 + dy**2)
