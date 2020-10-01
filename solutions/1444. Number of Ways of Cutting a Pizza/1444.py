class Solution:
    def ways(self, pizza: List[str], k: int) -> int:
        def hasApple(si: int, ei: int, sj: int, ej: int) -> int:
            if any(pizza[i][j] == 'A' for i in range(si, ei) for j in range(sj, ej)):
                return True

        def dfs(si: int, ei: int, sj: int, ej: int, k: int) -> int:
            if si >= ei or sj >= ej:
                return 0
            if k == 0:
                return 1
            if (si, ei, sj, ej, k) in memo:
                return memo[(si, ei, sj, ej, k)]

            ans = 0

            for i in range(si + 1, ei):
                if hasApple(si, i, sj, ej) and hasApple(i, ei, sj, ej):
                    ans += dfs(i, ei, sj, ej, k - 1)

            for j in range(sj + 1, ej):
                if hasApple(si, ei, sj, j) and hasApple(si, ei, j, ej):
                    ans += dfs(si, ei, j, ej, k - 1)

            memo[(si, ei, sj, ej, k)] = ans

            return ans

        memo = {}

        return dfs(0, len(pizza), 0, len(pizza[0]), k - 1) % int(1e9 + 7)
