class Solution:
  def countTriplets(self, nums: List[int]) -> int:
    kMax = 1 << 16
    ans = 0
    count = [0] * kMax  # {nums[i] & nums[j]: times}

    for a in nums:
      for b in nums:
        count[a & b] += 1

    for num in nums:
      for i in range(kMax):
        if (num & i) == 0:
          ans += count[i]

    return ans
