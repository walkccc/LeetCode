class Solution:
  def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
    graph = [[] for _ in range(n)]  # {a: [(b, probability_ab)]}
    maxHeap = [(-1.0, start)]   # (the probability to reach u, u)
    seen = [False] * n

    for i, ((u, v), prob) in enumerate(zip(edges, succProb)):
      graph[u].append((v, prob))
      graph[v].append((u, prob))

    while maxHeap:
      prob, u = heapq.heappop(maxHeap)
      prob *= -1
      if u == end:
        return prob
      if seen[u]:
        continue
      seen[u] = True
      for nextNode, edgeProb in graph[u]:
        if seen[nextNode]:
          continue
        heapq.heappush(maxHeap, (-prob * edgeProb, nextNode))

    return 0
