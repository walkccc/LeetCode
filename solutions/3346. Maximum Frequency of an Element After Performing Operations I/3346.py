from sortedcontainers import SortedDict


class Solution:
  def maxFrequency(self, nums: list[int], k: int, numOperations: int) -> int:
    ans = 1
    adjustable = 0
    count = collections.Counter(nums)
    line = SortedDict()
    candidates = set()

    for num in nums:
      line[num - k] = line.get(num - k, 0) + 1
      line[num + k + 1] = line.get(num + k + 1, 0) - 1
      candidates.add(num)
      candidates.add(num - k)
      candidates.add(num + k + 1)

    for num in sorted(candidates):
      adjustable += line.get(num, 0)
      adjusted = adjustable - count[num]
      ans = max(ans, count[num] + min(numOperations, adjusted))

    return ans
