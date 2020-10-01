class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        def dfs(ring: str, index: int) -> int:
            if index == len(key):
                return 0
            if (ring, index) in memo:
                return memo[(ring, index)]

            ans = float('inf')

            for i, r in enumerate(ring):
                if r == key[index]:
                    diff = min(i, len(ring) - i)
                    step = dfs(ring[i:] + ring[:i], index + 1)
                    ans = min(ans, diff + step)

            memo[(ring, index)] = ans
            return ans

        memo = {}

        return dfs(ring, 0) + len(key)
