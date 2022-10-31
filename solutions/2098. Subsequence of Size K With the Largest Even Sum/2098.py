class Solution:
  def largestEvenSum(self, nums: List[int], k: int) -> int:
    nums.sort()
    summ = sum(nums[-k:])
    if summ % 2 == 0:
      return summ

    minOdd = -1
    minEven = -1
    maxOdd = -1
    maxEven = -1

    for i in range(len(nums) - 1, len(nums) - k - 1, -1):
      if nums[i] & 1:
        minOdd = nums[i]
      else:
        minEven = nums[i]

    for i in range(len(nums) - k):
      if nums[i] & 1:
        maxOdd = nums[i]
      else:
        maxEven = nums[i]

    ans = -1

    if maxEven >= 0 and minOdd >= 0:
      ans = max(ans, summ + maxEven - minOdd)
    if maxOdd >= 0 and minEven >= 0:
      ans = max(ans, summ + maxOdd - minEven)
    return ans
