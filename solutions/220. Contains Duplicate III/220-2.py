class Solution:
  def containsNearbyAlmostDuplicate(
      self,
      nums: list[int],
      indexDiff: int,
      valueDiff: int,
  ) -> bool:
    if not nums or indexDiff <= 0 or valueDiff < 0:
      return False

    mn = min(nums)
    diff = valueDiff + 1  # In case that `valueDiff` equals 0.
    bucket = {}

    def getKey(num: int) -> int:
      return (num - mn) // diff

    for i, num in enumerate(nums):
      key = getKey(num)
      if key in bucket:  # the current bucket
        return True
      # the left adjacent bucket
      if key - 1 in bucket and num - bucket[key - 1] < diff:
        return True
      # the right adjacent bucket
      if key + 1 in bucket and bucket[key + 1] - num < diff:
        return True
      bucket[key] = num
      if i >= indexDiff:
        del bucket[getKey(nums[i - indexDiff])]

    return False
