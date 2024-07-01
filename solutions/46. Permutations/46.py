class Solution:
  def permute(self, nums: List[int]) -> List[List[int]]:
    ans = []
    used = [False] * len(nums)

    def dfs(path: List[int]) -> None:
      if len(path) == len(nums):
        ans.append(path.copy())
        return

      for i, num in enumerate(nums):
        if used[i]:
          continue
        used[i] = True
        path.append(num)
        dfs(path)
        path.pop()
        used[i] = False

    dfs([])
    return ans
