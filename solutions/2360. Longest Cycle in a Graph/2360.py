class Solution:
  def longestCycle(self, edges: List[int]) -> int:
    ans = -1
    time = 1
    timeVisited = [0] * len(edges)

    for i, edge in enumerate(edges):
      if timeVisited[i]:
        continue
      startTime = time
      u = i
      while u != -1 and not timeVisited[u]:
        timeVisited[u] = time
        time += 1
        u = edges[u]  # Move to the next node.
      if u != -1 and timeVisited[u] >= startTime:
        ans = max(ans, time - timeVisited[u])

    return ans
