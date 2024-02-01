class Solution:
  def countCompleteSubarrays(self, nums: List[int]) -> int:
    ans = 0
    distinct = len(set(nums))
    count = collections.Counter()

    l = 0
    for num in nums:
      count[num] += 1
      while len(count) == distinct:
        count[nums[l]] -= 1
        if count[nums[l]] == 0:
          del count[nums[l]]
        l += 1
      # Assume nums[r] = num,
      # nums[0..r], nums[1..r], ..., nums[l - 1..r] have k different values.
      ans += l

    return ans
