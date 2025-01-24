class Solution:
  def maximizeSumOfWeights(self, edges: list[list[int]], k: int) -> int:
    graph = [[] for _ in range(len(edges) + 1)]

    for u, v, w in edges:
      graph[u].append((v, w))
      graph[v].append((u, w))

    def dfs(u: int, prev: int) -> tuple[int, int]:
      """
      Returns
      (the weight sum of the subtree rooted at u with at most k - 1 children,
       the weight sum of the subtree rooted at u with at most k children).
      """
      weightSum = 0
      diffs = []
      for v, w in graph[u]:
        if v == prev:
          continue
        subK1, subK = dfs(v, u)
        weightSum += subK
        # If picking (u, v) makes the sum larger, we should pick it.
        diffs.append(max(0, subK1 - subK + w))
      return (weightSum + sum(heapq.nlargest(k - 1, diffs)),
              weightSum + sum(heapq.nlargest(k, diffs)))

    return dfs(0, -1)[1]
