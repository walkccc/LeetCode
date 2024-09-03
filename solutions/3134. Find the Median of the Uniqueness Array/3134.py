class Solution:
  def medianOfUniquenessArray(self, nums: list[int]):
    n = len(nums)
    subarrayCount = n * (n + 1) // 2
    medianCount = (subarrayCount + 1) // 2

    # Similar to 992. Subarrays with K Different Integers
    def subarraysWithAtMostKDistinct(k: int) -> int:
      res = 0
      count = collections.Counter()

      l = 0
      for r, num in enumerate(nums):
        count[num] += 1
        if count[num] == 1:
          k -= 1
        while k < 0:
          count[nums[l]] -= 1
          if count[nums[l]] == 0:
            k += 1
          l += 1
        res += r - l + 1  # nums[l..r], nums[l + 1..r], ..., nums[r]

      return res

    return bisect.bisect_left(
        range(1, n), medianCount,
        key=lambda m: subarraysWithAtMostKDistinct(m)) + 1
