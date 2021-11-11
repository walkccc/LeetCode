class Solution:
  def countMaxOrSubsets(self, nums: List[int]) -> int:
    ors = reduce(operator.or_, nums)

    self.ans = 0

    def dfs(i: int, path: int) -> None:
      if i == len(nums):
        if path == ors:
          self.ans += 1
        return

      dfs(i + 1, path)
      dfs(i + 1, path | nums[i])

    dfs(0, 0)

    return self.ans
