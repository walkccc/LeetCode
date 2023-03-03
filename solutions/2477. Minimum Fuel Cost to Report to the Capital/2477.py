class Solution:
  def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
    ans = 0
    graph = [[] for _ in range(len(roads) + 1)]

    for u, v in roads:
      graph[u].append(v)
      graph[v].append(u)

    def dfs(u: int, prev: int) -> int:
      nonlocal ans
      people = 1
      for v in graph[u]:
        if v == prev:
          continue
        people += dfs(v, u)
      if u > 0:
        # # of cars needed.
        ans += int(math.ceil(people / seats))
      return people

    dfs(0, -1)
    return ans
