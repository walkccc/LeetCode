class Solution:
  def countKDifference(self, nums: List[int], k: int) -> int:
    count = collections.Counter(nums)
    return sum(count[i] * count[i - k] for i in range(k + 1, 101))
