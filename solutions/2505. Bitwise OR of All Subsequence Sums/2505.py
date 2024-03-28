class Solution:
  def subsequenceSumOr(self, nums: List[int]) -> int:
    ans = 0
    prefix = 0

    for num in nums:
      prefix += num
      ans |= num | prefix

    return ans
