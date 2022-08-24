class Solution:
  def sumOfFlooredPairs(self, nums: List[int]) -> int:
    kMod = int(1e9) + 7
    kMax = max(nums)
    ans = 0
    count = [0] * (kMax + 1)

    for num in nums:
      count[num] += 1

    for i in range(1, kMax + 1):
      count[i] += count[i - 1]

    for i in range(1, kMax + 1):
      if count[i] > count[i - 1]:
        sum = 0
        j = 1
        while i * j <= kMax:
          lo = i * j - 1
          hi = i * (j + 1) - 1
          sum += (count[min(hi, kMax)] - count[lo]) * j
          j += 1
        ans += sum * (count[i] - count[i - 1])
        ans %= kMod

    return ans
