class Solution:
  def waysToBuildRooms(self, prevRoom: List[int]) -> int:
    kMod = 1_000_000_007
    graph = defaultdict(list)

    for i, prev in enumerate(prevRoom):
      graph[prev].append(i)

    def dfs(node: int) -> Tuple[int, int]:
      if not graph[node]:
        return 1, 1

      ans = 1
      l = 0

      for child in graph[node]:
        temp, r = dfs(child)
        ans = (ans * temp * math.comb(l + r, r)) % kMod
        l += r

      return ans, l + 1

    return dfs(0)[0]
