class Solution:
  def countExcellentPairs(self, nums: list[int], k: int) -> int:
    count = collections.Counter(map(int.bit_count, set(nums)))
    return sum(count[i] * count[j]
               for i in count
               for j in count
               if i + j >= k)
