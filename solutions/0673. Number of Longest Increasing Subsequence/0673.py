class Solution:
  def findNumberOfLIS(self, nums: List[int]) -> int:
    ans = 0
    maxLength = 0
    length = [1] * len(nums)  # length[i] := LIS's length ending w/ nums[i]
    count = [1] * len(nums)  # count[i] := # of the LIS ending w/ nums[i]

    # calculate length and count arrays
    for i, num in enumerate(nums):
      for j in range(i):
        if nums[j] < num:
          if length[i] < length[j] + 1:
            length[i] = length[j] + 1
            count[i] = count[j]
          elif length[i] == length[j] + 1:
            count[i] += count[j]

    # get # of LIS
    for i, l in enumerate(length):
      if l > maxLength:
        maxLength = l
        ans = count[i]
      elif l == maxLength:
        ans += count[i]

    return ans
