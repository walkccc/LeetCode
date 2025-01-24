class Solution:
  def subarrayLCM(self, nums: list[int], k: int) -> int:
    ans = 0

    for i, runningLcm in enumerate(nums):
      for j in range(i, len(nums)):
        runningLcm = math.lcm(runningLcm, nums[j])
        if runningLcm > k:
          break
        if runningLcm == k:
          ans += 1

    return ans
