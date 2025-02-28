class Solution:
  def countQuadruplets(self, nums: list[int]) -> int:
    n = len(nums)
    ans = 0
    count = collections.Counter()

    for c in range(n - 1, 1, -1):  # `c` also represents `d`.
      for b in range(c - 1, 0, -1):
        for a in range(b - 1, -1, -1):
          ans += count[nums[a] + nums[b] + nums[c]]
      count[nums[c]] += 1  # c := d

    return ans
