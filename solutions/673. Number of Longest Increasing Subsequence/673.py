class Solution:
  def findNumberOfLIS(self, nums: list[int]) -> int:
    ans = 0
    maxLength = 0
    # length[i] := the length of the LIS ending in nums[i]
    length = [1] * len(nums)
    # count[i] := the number of LIS's ending in nums[i]
    count = [1] * len(nums)

    # Calculate the `length` and `count` arrays.
    for i, num in enumerate(nums):
      for j in range(i):
        if nums[j] < num:
          if length[i] < length[j] + 1:
            length[i] = length[j] + 1
            count[i] = count[j]
          elif length[i] == length[j] + 1:
            count[i] += count[j]

    # Get the number of LIS.
    for i, l in enumerate(length):
      if l > maxLength:
        maxLength = l
        ans = count[i]
      elif l == maxLength:
        ans += count[i]

    return ans
