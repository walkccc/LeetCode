class Solution:
  def minimumFuelCost(self, roads: list[list[int]], seats: int) -> int:
    ans = 0
    tree = [[] for _ in range(len(roads) + 1)]

    for u, v in roads:
      tree[u].append(v)
      tree[v].append(u)

    def dfs(u: int, prev: int) -> int:
      nonlocal ans
      people = 1 + sum(dfs(v, u) for v in tree[u] if v != prev)
      if u > 0:
        # the number of cars needed
        ans += int(math.ceil(people / seats))
      return people

    dfs(0, -1)
    return ans
