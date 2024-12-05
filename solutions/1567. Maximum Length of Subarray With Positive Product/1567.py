class Solution:
  def getMaxLen(self, nums: list[int]) -> int:
    ans = 0
    # the maximum length of subarrays ending in `num` with a negative product
    neg = 0
    # the maximum length of subarrays ending in `num` with a positive product
    pos = 0

    for num in nums:
      pos = 0 if num == 0 else pos + 1
      neg = 0 if num == 0 or neg == 0 else neg + 1
      if num < 0:
        pos, neg = neg, pos
      ans = max(ans, pos)

    return ans
