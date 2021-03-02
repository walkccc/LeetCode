class Solution:
  def subsets(self, nums: List[int]) -> List[List[int]]:
    ans = []

    def dfs(s, path):
      ans.append(path)

      for i in range(s, len(nums)):
        dfs(i + 1, path + [nums[i]])

    dfs(0, [])

    return ans
