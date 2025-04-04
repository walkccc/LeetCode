class Solution:
  def maximumLength(self, nums: list[int]) -> int:
    maxNum = max(nums)
    count = collections.Counter(nums)
    ans = count[1] - (count[1] % 2 == 0) if 1 in count else 1

    for num in nums:
      if num == 1:
        continue
      length = 0
      x = num
      while x <= maxNum and x in count and count[x] >= 2:
        length += 2
        x *= x
      # x is now x^k, and the pattern is [x, ..., x^(k/2), x^(k/2), ..., x].
      # The goal is to determine if we can insert x^k in the middle of the
      # pattern to increase the length by 1. If not, we make x^(k/2) the middle
      # and decrease the length by 1.
      ans = max(ans, length + (1 if x in count else -1))

    return ans
