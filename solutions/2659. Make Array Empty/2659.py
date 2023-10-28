class Solution:
  def countOperationsToEmptyArray(self, nums: List[int]) -> int:
    n = len(nums)
    ans = n
    numToIndex = {}

    for i, num in enumerate(nums):
      numToIndex[num] = i

    nums.sort()

    for i in range(1, n):
      # On i-th step we've already removed i - 1 smallest nums and can ignore
      # them. If an element nums[i] has smaller index in origin array than
      # nums[i - 1], we should rotate whole left array n - i times to set
      # nums[i] element on the 1st position.
      if numToIndex[nums[i]] < numToIndex[nums[i - 1]]:
        ans += n - i

    return ans
