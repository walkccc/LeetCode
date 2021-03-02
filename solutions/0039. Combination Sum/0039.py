class Solution:
  def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
    ans = []

    def dfs(s, target, path):
      if target < 0:
        return
      if target == 0:
        ans.append(path)
        return

      for i in range(s, len(candidates)):
        dfs(i, target - candidates[i], path + [candidates[i]])

    candidates.sort()
    dfs(0, target, [])

    return ans
