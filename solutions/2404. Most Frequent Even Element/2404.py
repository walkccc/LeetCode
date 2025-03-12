class Solution:
  def mostFrequentEven(self, nums: list[int]) -> int:
    ans = -1
    count = collections.Counter()

    for num in nums:
      if num % 2 == 1:
        continue
      count[num] += 1
      newCount = count[num]
      maxCount = count[ans]
      if newCount > maxCount or newCount == maxCount and num < ans:
        ans = num

    return ans
