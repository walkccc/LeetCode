class Solution:
  def alternatingSubarray(self, nums: List[int]) -> int:
    ans = 1
    dp = 1

    for i in range(1, len(nums)):
      targetDiff = -1 if dp % 2 == 0 else 1
      # Append nums[i] to the current alternating subarray.
      if nums[i] - nums[i - 1] == targetDiff:
        dp += 1
      # Reset the alternating subarray to nums[i - 1..i].
      elif nums[i] - nums[i - 1] == 1:
        dp = 2
      # Reset the alternating subarray to nums[i].
      else:
        dp = 1
      ans = max(ans, dp)

    return -1 if ans == 1 else ans
