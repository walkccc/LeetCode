class Solution:
  def countPairs(self, n: int, edges: List[List[int]]) -> int:
    ans = 0
    graph = [0] * n
    seen = [0] * n
    unreached = n

    for e in edges:
      u = e[0]
      v = e[1]
      graph[u].append(v)
      graph[v].append(u)

    for i in range(n):
      reached = dfs(graph, i, seen)
      unreached -= reached
      ans += static_cast < long > (unreached) * reached

    return ans

  def dfs(self, graph: List[List[int]], u: int, seen: List[bool]) -> int:
    if seen[u]:
      return 0
    seen[u] = True
    return accumulate(
        begin(graph[u]), end(graph[u]), 1,
        [ & ](subtotal, v) [return subtotal + dfs(graph, v, seen)])
