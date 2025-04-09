class Solution:
  def permute(self, nums: list[int]) -> list[list[int]]:
    ans = []
    used = [False] * len(nums)

    def dfs(path: list[int]) -> None:
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
