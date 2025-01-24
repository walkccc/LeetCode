class Solution:
  def singleNumber(self, nums: list[int]) -> list[int]:
    xors = functools.reduce(operator.xor, nums)
    lowbit = xors & -xors
    ans = [0, 0]

    # Seperate `nums` into two groups by `lowbit`.
    for num in nums:
      if num & lowbit:
        ans[0] ^= num
      else:
        ans[1] ^= num

    return ans
