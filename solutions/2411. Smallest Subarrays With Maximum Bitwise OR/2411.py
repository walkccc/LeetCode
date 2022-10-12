class Solution:
  def smallestSubarrays(self, nums: List[int]) -> List[int]:
    kMaxDigit = 30
    ans = [1] * len(nums)
    # closest[j] := closest index i s.t. j-th bit of nums[i] is 1
    closest = [0] * kMaxDigit

    for i in reversed(range(len(nums))):
      for j in range(kMaxDigit):
        if nums[i] >> j & 1:
          closest[j] = i
        ans[i] = max(ans[i], closest[j] - i + 1)

    return ans
