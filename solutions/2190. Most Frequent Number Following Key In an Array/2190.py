class Solution:
  def mostFrequent(self, nums: list[int], key: int) -> int:
    count = collections.Counter()

    for a, b in itertools.pairwise(nums):
      if a == key:
        count[b] += 1

    return max(count, key=lambda num: count[num])
