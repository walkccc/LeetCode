class Solution:
  def uniqueXorTriplets(self, nums: list[int]) -> int:
    n = len(nums)
    if n == 1:
      return 1
    pairs = set(nums[i] ^ nums[j]
                for i, j in itertools.combinations(range(n), 2))
    return len(set(pair ^ num
                   for pair in pairs
                   for num in nums))
