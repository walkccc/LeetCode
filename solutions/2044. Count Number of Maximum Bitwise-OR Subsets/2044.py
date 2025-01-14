class Solution:
  def countMaxOrSubsets(self, nums: list[int]) -> int:
    ors = functools.reduce(operator.or_, nums)
    ans = 0

    def dfs(i: int, path: int) -> None:
      nonlocal ans
      if i == len(nums):
        if path == ors:
          ans += 1
        return

      dfs(i + 1, path)
      dfs(i + 1, path | nums[i])

    dfs(0, 0)
    return ans
