class Solution:
  def minCapability(self, nums: List[int], k: int) -> int:
    l = min(nums)
    r = max(nums)

    def stolenHouses(capacity: int) -> int:
      stolen = 0
      i = 0
      while i < len(nums):
        if nums[i] <= capacity:
          stolen += 1
          i += 1
        i += 1
      return stolen

    while l < r:
      m = (l + r) // 2
      if stolenHouses(m) >= k:
        r = m
      else:
        l = m + 1

    return l
