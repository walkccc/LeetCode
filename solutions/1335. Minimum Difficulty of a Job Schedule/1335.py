class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)

        if d > n:
            return -1

        dp = [[float('inf')] * (d + 1) for _ in range(n + 1)]
        dp[0][0] = 0

        for i in range(1, n + 1):
            for k in range(1, d + 1):
                maxDifficulty = 0
                for j in range(i, k - 1, -1):
                    maxDifficulty = max(maxDifficulty, jobDifficulty[j - 1])
                    dp[i][k] = min(dp[i][k], dp[j - 1][k - 1] + maxDifficulty)

        return dp[n][d]
