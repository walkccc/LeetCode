class Solution:
  def smallestSubarrays(self, nums: list[int]) -> list[int]:
    MAX_BIT = 30
    ans = [1] * len(nums)
    # closest[j] := the closest index i s.t. the j-th bit of nums[i] is 1
    closest = [0] * MAX_BIT

    for i in reversed(range(len(nums))):
      for j in range(MAX_BIT):
        if nums[i] >> j & 1:
          closest[j] = i
        ans[i] = max(ans[i], closest[j] - i + 1)

    return ans
