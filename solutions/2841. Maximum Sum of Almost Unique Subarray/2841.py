class Solution:
  def maxSum(self, nums: List[int], m: int, k: int) -> int:
    ans = 0
    summ = 0
    count = collections.Counter()

    for i, num in enumerate(nums):
      summ += num
      count[num] += 1
      if i >= k:
        numToRemove = nums[i - k]
        summ -= numToRemove
        count[numToRemove] -= 1
        if count[numToRemove] == 0:
          del count[numToRemove]
      if len(count) >= m:
        ans = max(ans, summ)

    return ans
