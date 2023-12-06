class Solution:
  def numSubseq(self, nums: List[int], target: int) -> int:
    kMod = 1_000_000_007
    n = len(nums)
    ans = 0

    nums.sort()

    l = 0
    r = n - 1
    while l <= r:
      if nums[l] + nums[r] <= target:
        ans += pow(2, r - l, kMod)
        l += 1
      else:
        r -= 1

    return ans % kMod
