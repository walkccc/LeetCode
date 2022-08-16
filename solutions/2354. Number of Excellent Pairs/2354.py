class Solution:
  def countExcellentPairs(self, nums: List[int], k: int) -> int:
    count = Counter(map(int.bit_count, set(nums)))
    return sum(count[i] * count[j]
               for i in count
               for j in count
               if i + j >= k)
