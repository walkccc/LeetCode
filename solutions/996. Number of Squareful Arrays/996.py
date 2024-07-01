class Solution:
  def numSquarefulPerms(self, nums: List[int]) -> int:
    ans = 0
    used = [False] * len(nums)

    def isSquare(num: int) -> bool:
      root = int(math.sqrt(num))
      return root * root == num

    def dfs(path: List[int]) -> None:
      nonlocal ans
      if len(path) > 1 and not isSquare(path[-1] + path[-2]):
        return
      if len(path) == len(nums):
        ans += 1
        return

      for i, a in enumerate(nums):
        if used[i]:
          continue
        if i > 0 and nums[i] == nums[i - 1] and not used[i - 1]:
          continue
        used[i] = True
        dfs(path + [a])
        used[i] = False

    nums.sort()
    dfs([])
    return ans
