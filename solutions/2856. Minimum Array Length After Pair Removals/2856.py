class Solution:
  def minLengthAfterRemovals(self, nums: List[int]) -> int:
    n = len(nums)
    count = collections.Counter(nums)
    maxFreq = max(count.values())

    # The num with max freq cancels all the other nums.
    if maxFreq <= n / 2:
      return n % 2
    # The num with max freq cancels all the remaining nums.
    return maxFreq - (n - maxFreq)
