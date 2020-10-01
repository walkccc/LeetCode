class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        def dfs(i: int, j: int) -> int:
            if not 0 <= i < len(grid) or not 0 <= j < len(grid[0]):
                return 0
            if grid[i][j] == 0 or seen[i][j]:
                return 0

            seen[i][j] = True

            return 1 + dfs(i + 1, j) + dfs(i - 1, j) + dfs(i, j + 1) + dfs(i, j - 1)

        ans = 0
        seen = [[False] * len(grid[0]) for _ in range(len(grid))]

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                ans = max(ans, dfs(i, j))

        return ans
