class Solution:
  def containsNearbyAlmostDuplicate(self, nums: List[int], indexDiff: int, valueDiff: int) -> bool:
    if not nums or indexDiff <= 0 or valueDiff < 0:
      return False

    mini = min(nums)
    diff = valueDiff + 1  # In case of valueDiff = 0
    bucket = {}

    def getKey(num: int) -> int:
      return (num - mini) // diff

    for i, num in enumerate(nums):
      key = getKey(num)
      if key in bucket:  # Current bucket
        return True
      # Left adjacent bucket
      if key - 1 in bucket and num - bucket[key - 1] < diff:
        return True
      # Right adjacent bucket
      if key + 1 in bucket and bucket[key + 1] - num < diff:
        return True
      bucket[key] = num
      if i >= indexDiff:
        del bucket[getKey(nums[i - indexDiff])]

    return False
