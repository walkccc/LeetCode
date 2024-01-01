class Solution:
  def maxSumRangeQuery(self, nums: List[int], requests: List[List[int]]) -> int:
    kMod = 1_000_000_007
    ans = 0
    # count[i] := the number of times nums[i] has been requested
    count = [0] * len(nums)

    for start, end in requests:
      count[start] += 1
      if end + 1 < len(nums):
        count[end + 1] -= 1

    for i in range(1, len(nums)):
      count[i] += count[i - 1]

    for num, c in zip(sorted(nums), sorted(count)):
      ans += num * c
      ans %= kMod

    return ans
