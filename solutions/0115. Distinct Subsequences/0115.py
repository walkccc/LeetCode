class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m = len(s)
        n = len(t)

        dp = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(m + 1):
            for j in range(n + 1):
                if j == 0:
                    dp[i][j] = 1
                elif i == 0:
                    dp[i][j] = 0
                else:
                    dp[i][j] = dp[i - 1][j] + \
                        (dp[i - 1][j - 1] if s[i - 1] == t[j - 1] else 0)

        return dp[m][n]
