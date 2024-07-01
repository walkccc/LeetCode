class Solution:
  def sumOfUnique(self, nums: List[int]) -> int:
    return sum(num
               for num, freq in collections.Counter(nums).items()
               if freq == 1)
