class Solution:
  def largestTriangleArea(self, points: list[list[int]]) -> float:
    ans = 0

    for Ax, Ay in points:
      for Bx, By in points:
        for Cx, Cy in points:
          ans = max(ans, 0.5 * abs((Bx - Ax) * (Cy - Ay) -
                                   (Cx - Ax) * (By - Ay)))

    return ans
