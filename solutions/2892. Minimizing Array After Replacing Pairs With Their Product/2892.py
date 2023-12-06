class Solution:
  def minArrayLength(self, nums: List[int], k: int) -> int:
    count = 0
    prod = -1

    for num in nums:
      if num == 0:
        return 1
      if prod != -1 and prod * num <= k:
        prod *= num
      else:
        prod = num
        count += 1

    return count
