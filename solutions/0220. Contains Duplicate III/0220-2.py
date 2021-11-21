class Solution:
  def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
    if not nums or k <= 0 or t < 0:
      return False

    mini = min(nums)
    diff = t + 1
    bucket = {}

    def getKey(num: int) -> int:
      return (num - mini) // diff

    for i, num in enumerate(nums):
      key = getKey(num)
      if key in bucket:  # current bucket
        return True
      # left adjacent bucket
      if key - 1 in bucket and num - bucket[key - 1] < diff:
        return True
      # right adjacent bucket
      if key + 1 in bucket and bucket[key + 1] - num < diff:
        return True
      bucket[key] = num
      if i >= k:
        del bucket[getKey(nums[i - k])]

    return False
