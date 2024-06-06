class Solution:
  def minLengthAfterRemovals(self, nums: List[int]) -> int:
    n = len(nums)
    count = collections.Counter(nums)
    maxFreq = max(count.values())

    # The number with the maximum frequency cancel all the other numbers.
    if maxFreq <= n / 2:
      return n % 2
    # The number with the maximum frequency cancel all the remaining numbers.
    return maxFreq - (n - maxFreq)
