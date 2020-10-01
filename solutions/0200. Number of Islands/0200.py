class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def dfs(i: int, j: int) -> None:
            if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]) or visited[i][j] or grid[i][j] == '0':
                return

            visited[i][j] = True

            dfs(i + 1, j)
            dfs(i - 1, j)
            dfs(i, j + 1)
            dfs(i, j - 1)

        if not grid:
            return 0

        m = len(grid)
        n = len(grid[0])

        ans = 0
        visited = [[False] * n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                if not visited[i][j] and grid[i][j] == '1':
                    ans += 1
                    dfs(i, j)

        return ans
