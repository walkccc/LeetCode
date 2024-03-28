class Solution:
  def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
    seen = set()

    for i, num in enumerate(nums):
      if i > k:
        seen.remove(nums[i - k - 1])
      if num in seen:
        return True
      seen.add(num)

    return False
