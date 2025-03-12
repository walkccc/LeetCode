class Solution:
  def countTriplets(self, nums: list[int]) -> int:
    MAX = 1 << 16
    ans = 0
    count = [0] * MAX  # {nums[i] & nums[j]: times}

    for a in nums:
      for b in nums:
        count[a & b] += 1

    for num in nums:
      for i in range(MAX):
        if (num & i) == 0:
          ans += count[i]

    return ans
