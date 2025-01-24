class Solution:
  def countOperationsToEmptyArray(self, nums: list[int]) -> int:
    n = len(nums)
    ans = n
    numToIndex = {}

    for i, num in enumerate(nums):
      numToIndex[num] = i

    nums.sort()

    for i in range(1, n):
      # On the i-th step we've already removed the i - 1 smallest numbers and
      # can ignore them. If an element nums[i] has smaller index in origin
      # array than nums[i - 1], we should rotate the whole left array n - i
      # times to set nums[i] element on the first position.
      if numToIndex[nums[i]] < numToIndex[nums[i - 1]]:
        ans += n - i

    return ans
