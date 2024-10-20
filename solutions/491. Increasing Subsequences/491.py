class Solution:
  def findSubsequences(self, nums: list[int]) -> list[list[int]]:
    ans = []

    def dfs(s: int, path: list[int]) -> None:
      if len(path) > 1:
        ans.append(path)

      used = set()

      for i in range(s, len(nums)):
        if nums[i] in used:
          continue
        if not path or nums[i] >= path[-1]:
          used.add(nums[i])
          dfs(i + 1, path + [nums[i]])

    dfs(0, [])
    return ans
