class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        def squareSum(r1: int, c1: int, r2: int, c2: int) -> int:
            return prefixSum[r2 + 1][c2 + 1] - prefixSum[r1][c2 + 1] - prefixSum[r2 + 1][c1] + prefixSum[r1][c1]

        m = len(mat)
        n = len(mat[0])

        ans = 0
        prefixSum = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                prefixSum[i][j] = mat[i - 1][j - 1] + prefixSum[i][j - 1] + \
                    prefixSum[i - 1][j] - prefixSum[i - 1][j - 1]

        for i in range(m):
            for j in range(n):
                for length in range(ans, min(m - i, n - j)):
                    if squareSum(i, j, i + length, j + length) > threshold:
                        break
                    ans = max(ans, length + 1)

        return ans
