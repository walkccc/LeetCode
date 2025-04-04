class Solution:
  def combinationSum2(self, candidates: list[int],
                      target: int) -> list[list[int]]:
    ans = []

    def dfs(s: int, target: int, path: list[int]) -> None:
      if target < 0:
        return
      if target == 0:
        ans.append(path.copy())
        return

      for i in range(s, len(candidates)):
        if i > s and candidates[i] == candidates[i - 1]:
          continue
        path.append(candidates[i])
        dfs(i + 1, target - candidates[i], path)
        path.pop()

    candidates.sort()
    dfs(0, target, [])
    return ans
