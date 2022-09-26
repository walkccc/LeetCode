class Solution:
  def countPoints(self, points: List[List[int]], queries: List[List[int]]) -> List[int]:
    ans = []

    def squared(x):
      return x * x

    for xj, yj, r in queries:
      rSquared = r**2
      count = 0
      for xi, yi in points:
        count += (xi - xj)**2 + (yi - yj)**2 <= rSquared
      ans.append(count)

    return ans
