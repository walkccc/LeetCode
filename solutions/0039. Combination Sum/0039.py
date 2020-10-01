class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(target: int, s: int, path: List[int]) -> None:
            if target < 0:
                return
            if target == 0:
                ans.append(path)
                return

            for i in range(s, len(candidates)):
                dfs(target - candidates[i], i, path + [candidates[i]])

        ans = []

        candidates.sort()
        dfs(target, 0, [])

        return ans
