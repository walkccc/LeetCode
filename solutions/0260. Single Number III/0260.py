import functools


class Solution:
  def singleNumber(self, nums: List[int]) -> List[int]:
    ans = [0, 0]

    xor = functools.reduce(lambda x, y: x ^ y, nums)
    xor &= -xor

    for num in nums:
      if num & xor:
        ans[0] ^= num
      else:
        ans[1] ^= num

    return ans
