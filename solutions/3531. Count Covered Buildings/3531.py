class Solution:
  def countCoveredBuildings(self, n: int, buildings: list[list[int]]) -> int:
    northernmost = [math.inf] * (n + 1)
    southernmost = [0] * (n + 1)
    westernmost = [math.inf] * (n + 1)
    easternmost = [0] * (n + 1)

    for x, y in buildings:
      northernmost[x] = min(northernmost[x], y)
      southernmost[x] = max(southernmost[x], y)
      westernmost[y] = min(westernmost[y], x)
      easternmost[y] = max(easternmost[y], x)

    return sum(northernmost[x] < y < southernmost[x]
               and westernmost[y] < x < easternmost[y]
               for x, y in buildings)
