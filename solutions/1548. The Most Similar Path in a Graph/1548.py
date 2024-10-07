class Solution:
  def mostSimilar(self, n: int, roads: list[list[int]], names: list[str],
                  targetPath: list[str]) -> list[int]:
    # cost[i][j] := the minimum cost to start from names[i] in path[j]
    cost = [[-1] * len(targetPath) for _ in range(len(names))]
    # next[i][j] := the best next of names[i] in path[j]
    next = [[0] * len(targetPath) for _ in range(len(names))]
    graph = [[] for _ in range(n)]

    for u, v in roads:
      graph[u].append(v)
      graph[v].append(u)

    minDist = math.inf
    start = 0

    def dfs(nameIndex: int, pathIndex: int) -> int:
      if cost[nameIndex][pathIndex] != -1:
        return cost[nameIndex][pathIndex]

      editDist = names[nameIndex] != targetPath[pathIndex]
      if pathIndex == len(targetPath) - 1:
        return editDist

      minDist = math.inf

      for v in graph[nameIndex]:
        dist = dfs(v, pathIndex + 1)
        if dist < minDist:
          minDist = dist
          next[nameIndex][pathIndex] = v

      cost[nameIndex][pathIndex] = editDist + minDist
      return editDist + minDist

    for i in range(n):
      dist = dfs(i, 0)
      if dist < minDist:
        minDist = dist
        start = i

    ans = []

    while len(ans) < len(targetPath):
      ans.append(start)
      start = next[start][len(ans) - 1]

    return ans
