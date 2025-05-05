class Solution:
  def minTaps(self, n: int, ranges: list[int]) -> int:
    nums = [0] * (n + 1)

    for i, range_ in enumerate(ranges):
      l = max(0, i - range_)
      r = min(n, range_ + i)
      nums[l] = max(nums[l], r - l)

    ans = 0
    end = 0
    farthest = 0

    for i in range(n):
      farthest = max(farthest, i + nums[i])
      if i == end:
        ans += 1
        end = farthest

    return ans if end == n else -1
