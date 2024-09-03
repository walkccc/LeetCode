class Solution:
  def distanceToCycle(self, n: int, edges: list[list[int]]) -> list[int]:
    ans = [0] * n
    graph = [[] for _ in range(n)]

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    NO_RANK = -2

    # The minRank that u can reach with forward edges
    def getRank(u: int, currRank: int, rank: list[int]) -> int:
      if rank[u] != NO_RANK:  # The rank is already determined
        return rank[u]

      rank[u] = currRank
      minRank = currRank

      for v in graph[u]:
        # Visited or parent (that's why NO_RANK = -2 instead of -1)
        if rank[v] == len(rank) or rank[v] == currRank - 1:
          continue
        nextRank = getRank(v, currRank + 1, rank)
        # NextRank should > currRank if there's no cycle
        if nextRank <= currRank:
          cycle.append(v)
        minRank = min(minRank, nextRank)

      rank[u] = len(rank)  # Mark as visited.
      return minRank

    # rank[i] := the minimum node that node i can reach with forward edges
    # Initialize with NO_RANK = -2 to indicate not visited.
    cycle = []
    getRank(0, 0, [NO_RANK] * n)

    q = collections.deque(cycle)
    seen = set(cycle)

    dist = 0
    while q:
      dist += 1
      for _ in range(len(q)):
        u = q.popleft()
        for v in graph[u]:
          if v in seen:
            continue
          q.append(v)
          seen.add(v)
          ans[v] = dist

    return ans
