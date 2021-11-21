class Solution:
  def combinationSum4(self, nums: List[int], target: int) -> int:
    m = [-1] * (target + 1)
    m[0] = 1

    return self.dp(nums, target, m)

  def dp(self, nums: List[int], target: int, m: List[int]) -> int:
    if target < 0:
      return 0
    if m[target] != -1:
      return m[target]

    ans = 0

    for num in nums:
      ans += self.dp(nums, target - num, m)

    m[target] = ans

    return ans
