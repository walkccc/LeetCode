class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(target: int, s: int, path: List[int]) -> None:
            if target < 0:
                return
            if target == 0:
                ans.append(path)
                return

            for i in range(s, len(candidates)):
                if i > s and candidates[i] == candidates[i - 1]:
                    continue
                dfs(target - candidates[i], i + 1, path + [candidates[i]])

        ans = []

        candidates.sort()
        dfs(target, 0, [])

        return ans
