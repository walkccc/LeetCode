class Solution:
  # Same as 3095. Shortest Subarray With OR at Least K I
  def minimumSubarrayLength(self, nums: list[int], k: int) -> int:
    ans = len(nums) + 1
    ors = 0
    count = collections.Counter()

    l = 0
    for r, num in enumerate(nums):
      ors = self._orNum(ors, num, count)
      while ors >= k and l <= r:
        ans = min(ans, r - l + 1)
        ors = self._undoOrNum(ors, nums[l], count)
        l += 1

    return -1 if ans == len(nums) + 1 else ans

  def _orNum(self, ors: int, num: int, count: dict[int, int]) -> int:
    for i in range(30):
      if num >> i & 1:
        count[i] += 1
        if count[i] == 1:
          ors += 1 << i
    return ors

  def _undoOrNum(self, ors: int, num: int, count: dict[int, int]) -> int:
    for i in range(30):
      if num >> i & 1:
        count[i] -= 1
        if count[i] == 0:
          ors -= 1 << i
    return ors
