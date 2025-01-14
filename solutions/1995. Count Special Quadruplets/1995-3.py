class Solution:
  def countQuadruplets(self, nums: list[int]) -> int:
    n = len(nums)
    ans = 0
    count = collections.Counter()

    #    nums[a] + nums[b] + nums[c] == nums[d]
    # => nums[a] + nums[b] == nums[d] - nums[c]
    for b in range(n - 1, 0, -1):  # `b` also represents `c`.
      for a in range(b - 1, -1, -1):
        ans += count[nums[a] + nums[b]]
      for d in range(n - 1, b, -1):
        count[nums[d] - nums[b]] += 1  # b := c

    return ans
