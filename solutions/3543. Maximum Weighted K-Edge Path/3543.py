class Solution:
  def maxWeight(self, n: int, edges: list[list[int]], k: int, t: int) -> int:
    graph = [[] for _ in range(n)]
    # dp[u][i] := the set of possible path sums ending at node u with i edges
    dp = [defaultdict(set) for _ in range(n)]

    for u, v, w in edges:
      graph[u].append((v, w))

    for u in range(n):
      dp[u][0].add(0)  # zero edges = sum 0

    for i in range(k):
      for u in range(n):
        for currSum in dp[u][i]:
          for v, w in graph[u]:
            newSum = currSum + w
            if newSum < t:
              dp[v][i + 1].add(newSum)

    ans = -1

    for u in range(n):
      if k in dp[u]:
        ans = max(ans, max(dp[u][k]))

    return ans
