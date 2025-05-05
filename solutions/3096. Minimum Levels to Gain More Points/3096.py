class Solution:
  def minimumLevels(self, possible: list[int]) -> int:
    n = len(possible)
    nums = [num if num == 1 else -1 for num in possible]
    prefix = list(itertools.accumulate(nums, initial=0))

    for i in range(1, n):
      if prefix[i] > prefix[n] - prefix[i]:
        return i

    return -1
