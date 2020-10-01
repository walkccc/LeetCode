class Solution:
    def leastOpsExpressTarget(self, x: int, target: int) -> int:
        def dfs(x: int, target: int) -> int:
            if target in memo:
                return memo[target]
            if x > target:
                return min(2 * target - 1, 2 * (x - target))
            if x == target:
                return 0

            prod = x
            n = 0

            while prod < target:
                prod *= x
                n += 1

            if prod == target:
                memo[target] = n
                return memo[target]

            memo[target] = float('inf')
            if prod < 2 * target:
                memo[target] = dfs(x, prod - target) + n + 1
            memo[target] = min(memo[target], dfs(x, target - prod // x) + n)

            return memo[target]

        memo = {}

        return dfs(x, target)
