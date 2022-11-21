class Solution:
  def destroyTargets(self, nums: List[int], space: int) -> int:
    count = Counter([num % space for num in nums])
    maxCount = max(count.values())
    return min(num for num in nums if count[num % space] == maxCount)
