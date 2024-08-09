class Solution:
  def subsetXORSum(self, nums: List[int]) -> int:
    def dfs(i: int, xors: int) -> int:
      if i == len(nums):
        return xors

      x = dfs(i + 1, xors)
      y = dfs(i + 1, nums[i] ^ xors)
      return x + y

    return dfs(0, 0)
