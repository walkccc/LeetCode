class Solution:
  def maximumImportance(self, n: int, roads: list[list[int]]) -> int:
    count = [0] * n

    for u, v in roads:
      count[u] += 1
      count[v] += 1

    count.sort()
    return sum((i + 1) * c for i, c in enumerate(count))
