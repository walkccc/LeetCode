class Solution:
  def maxEqualFreq(self, nums: List[int]) -> int:
    ans = 0
    maxFreq = 0
    count = collections.Counter()
    freq = collections.Counter()

    for i, num in enumerate(nums):
      freq[count[num]] -= 1
      count[num] += 1
      freq[count[num]] += 1
      maxFreq = max(maxFreq, count[num])
      if maxFreq == 1 or maxFreq * freq[maxFreq] == i or (maxFreq - 1) * (freq[maxFreq - 1] + 1) == i:
        ans = i + 1

    return ans
