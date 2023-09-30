class Solution:
  def minCapability(self, nums: List[int], k: int) -> int:
    def numStolenHouses(capacity: int) -> int:
      stolenHouses = 0
      i = 0
      while i < len(nums):
        if nums[i] <= capacity:
          stolenHouses += 1
          i += 1
        i += 1
      return stolenHouses

    return bisect.bisect_left(range(max(nums)), k,
                              key=lambda m: numStolenHouses(m))
