class Solution:
  def minCost(self, grid: list[list[int]]) -> int:
    m = len(grid)
    n = len(grid[0])
    dirs = ((0, 1), (0, -1), (1, 0), (-1, 0))
    dp = [[-1] * n for _ in range(m)]
    q = collections.deque()

    def dfs(i: int, j: int, cost: int) -> None:
      if i < 0 or i == m or j < 0 or j == n:
        return
      if dp[i][j] != -1:
        return

      dp[i][j] = cost
      q.append((i, j))
      dx, dy = dirs[grid[i][j] - 1]
      dfs(i + dx, j + dy, cost)

    dfs(0, 0, 0)

    cost = 0
    while q:
      cost += 1
      for _ in range(len(q)):
        i, j = q.popleft()
        for dx, dy in dirs:
          dfs(i + dx, j + dy, cost)

    return dp[-1][-1]
