class Solution:
  def distinctNumbers(self, nums: list[int], k: int) -> list[int]:
    ans = []
    count = collections.Counter()
    distinct = 0

    for i, num in enumerate(nums):
      count[num] += 1
      if count[num] == 1:
        distinct += 1
      if i >= k:
        count[nums[i - k]] -= 1
        if count[nums[i - k]] == 0:
          distinct -= 1
      if i >= k - 1:
        ans.append(distinct)

    return ans
