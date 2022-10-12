class Solution:
  def smallestDistancePair(self, nums: List[int], k: int) -> int:
    nums.sort()

    l = 0
    r = nums[-1] - nums[0]

    while l < r:
      m = (l + r) // 2
      count = 0

      j = 0
      for i in range(len(nums)):
        while j < len(nums) and nums[j] <= nums[i] + m:
          j += 1
        count += j - i - 1

      if count < k:
        l = m + 1
      else:
        r = m

    return l
