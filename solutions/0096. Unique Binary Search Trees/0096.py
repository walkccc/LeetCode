class Solution:
    def numTrees(self, n: int) -> int:
        G = [0] * (n + 1)

        G[0] = 1
        G[1] = 1

        for i in range(2, n + 1):
            for j in range(i):
                G[i] += G[j] * G[i - j - 1]

        return G[n]
