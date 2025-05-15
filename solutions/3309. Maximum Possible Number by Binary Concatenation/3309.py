class Solution:
  def maxGoodNumber(self, nums: list[int]) -> int:
    ans = 0

    def concat(a: int, b: int) -> int:
      """Returns the concatenation of the binary representations of a and b."""
      return (a << b.bit_length()) + b

    nums.sort(key=functools.cmp_to_key(
        lambda a, b: concat(b, a) - concat(a, b)))

    for num in nums:
      ans = concat(ans, num)

    return ans
