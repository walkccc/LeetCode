class Solution:
  def makesquare(self, nums: List[int]) -> bool:
    if len(nums) < 4:
      return False

    perimeter = sum(nums)
    if perimeter % 4 != 0:
      return False

    nums = sorted(nums)[::-1]

    def dfs(selected: int, edges: List[int]) -> bool:
      if selected == len(nums):
        return all(edge == edges[0] for edge in edges)

      for i, edge in enumerate(edges):
        if nums[selected] > edge:
          continue
        edges[i] -= nums[selected]
        if dfs(selected + 1, edges):
          return True
        edges[i] += nums[selected]

      return False

    return dfs(0, [perimeter // 4] * 4)
