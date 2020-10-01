class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []

        self.dfs(n, k, 1, [], ans)

        return ans

    def dfs(self, n: int, k: int, s: int, path: List[int], ans: List[List[int]]) -> None:
        if k == 0:
            ans.append(path)
            return

        for i in range(s, n + 1):
            self.dfs(n, k - 1, i + 1, path + [i], ans)
