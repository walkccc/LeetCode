class Solution:
  def getLargestOutlier(self, nums: list[int]) -> int:
    ans = -math.inf
    summ = sum(nums)
    count = collections.Counter(nums)

    for num in nums:
      withoutNum = summ - num
      if withoutNum % 2 == 0:
        specialSum = withoutNum // 2  # the sum of special numbers
        if count[specialSum] > (1 if num == specialSum else 0):
          ans = max(ans, num)

    return ans
