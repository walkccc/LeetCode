class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        def dfs(i: int, j: int, maxi: int) -> int:
            if not 0 <= i < len(matrix) or not 0 <= j < len(matrix[0]) or matrix[i][j] <= maxi:
                return 0
            if cached[i][j] != 0:
                return cached[i][j]

            cached[i][j] = 1 + max(dfs(i + 1, j, matrix[i][j]),
                                   dfs(i - 1, j, matrix[i][j]),
                                   dfs(i, j + 1, matrix[i][j]),
                                   dfs(i, j - 1, matrix[i][j]))

            return cached[i][j]

        if not matrix:
            return 0

        ans = 0
        cached = [[0] * len(matrix[0]) for _ in range(len(matrix))]

        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                ans = max(ans, dfs(i, j, float('-inf')))

        return ans
