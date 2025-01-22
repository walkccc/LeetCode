class Solution:
  def subsets(self, nums: list[int]) -> list[list[int]]:
    ans = []

    def dfs(s: int, path: list[int]) -> None:
      ans.append(path)

      for i in range(s, len(nums)):
        dfs(i + 1, path + [nums[i]])

    dfs(0, [])
    return ans
