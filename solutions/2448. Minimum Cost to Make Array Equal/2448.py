class Solution:
  def minCost(self, nums: List[int], cost: List[int]) -> int:
    ans = 0
    l = min(nums)
    r = max(nums)

    def getCost(target: int) -> int:
      return sum(abs(num - target) * c for num, c in zip(nums, cost))

    while l < r:
      m = (l + r) // 2
      cost1 = getCost(m)
      cost2 = getCost(m + 1)
      ans = min(cost1, cost2)
      if cost1 < cost2:
        r = m
      else:
        l = m + 1

    return ans
