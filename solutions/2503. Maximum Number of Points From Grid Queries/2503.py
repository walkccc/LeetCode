from dataclasses import dataclass


@dataclass(frozen=True)
class IndexedQuery:
  queryIndex: int
  query: int

  def __iter__(self):
    yield self.queryIndex
    yield self.query


class Solution:
  def maxPoints(self, grid: list[list[int]], queries: list[int]) -> list[int]:
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(grid)
    n = len(grid[0])
    ans = [0] * len(queries)
    minHeap = [(grid[0][0], 0, 0)]  # (grid[i][j], i, j)
    seen = {(0, 0)}
    accumulate = 0

    for queryIndex, query in sorted([IndexedQuery(i, query)
                                     for i, query in enumerate(queries)],
                                    key=lambda x: x.query):
      while minHeap:
        val, i, j = heapq.heappop(minHeap)
        if val >= query:
          # The smallest neighbor is still larger than `query`, so no need to
          # keep exploring. Re-push (i, j, grid[i][j]) back to the `minHeap`.
          heapq.heappush(minHeap, (val, i, j))
          break
        accumulate += 1
        for dx, dy in dirs:
          x = i + dx
          y = j + dy
          if x < 0 or x == m or y < 0 or y == n:
            continue
          if (x, y) in seen:
            continue
          heapq.heappush(minHeap, (grid[x][y], x, y))
          seen.add((x, y))
      ans[queryIndex] = accumulate

    return ans
