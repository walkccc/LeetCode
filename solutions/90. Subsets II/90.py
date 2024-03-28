class Solution:
  def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
    ans = []

    def dfs(s: int, path: List[int]) -> None:
      ans.append(path)
      if s == len(nums):
        return

      for i in range(s, len(nums)):
        if i > s and nums[i] == nums[i - 1]:
          continue
        dfs(i + 1, path + [nums[i]])

    nums.sort()
    dfs(0, [])
    return ans
