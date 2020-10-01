class Solution:
    def maxDotProduct(self, A: List[int], B: List[int]) -> int:
        m = len(A)
        n = len(B)

        # dp[i][j]: the maxDotProduct of A[0..i - 1] and B[0..j - 1]
        dp = [[float('-inf')] * (n + 1) for _ in range(m + 1)]

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                product = A[i - 1] * B[j - 1]
                # dp[i][j] = max(A[i - 1] * B[j - 1], if dp[i - 1][j - 1] <= 0
                #                dp[i - 1][j - 1] + A[i - 1] * B[j - 1], if dp[i - 1][j - 1] > 0
                #                dp[i - 1][j]
                #                dp[i][j - 1]
                dp[i][j] = max(product, dp[i - 1][j - 1] +
                               product, dp[i - 1][j], dp[i][j - 1])

        return dp[m][n]
