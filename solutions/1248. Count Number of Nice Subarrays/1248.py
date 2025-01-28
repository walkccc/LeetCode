class Solution:
  def numberOfSubarrays(self, nums: list[int], k: int) -> int:
    def numberOfSubarraysAtMost(k: int) -> int:
      ans = 0
      l = 0
      r = 0

      while r <= len(nums):
        if k >= 0:
          ans += r - l
          if r == len(nums):
            break
          if nums[r] & 1:
            k -= 1
          r += 1
        else:
          if nums[l] & 1:
            k += 1
          l += 1
      return ans

    return numberOfSubarraysAtMost(k) - numberOfSubarraysAtMost(k - 1)
