class Solution:
  def minPatches(self, nums: list[int], n: int) -> int:
    ans = 0
    i = 0  # nums' index
    miss = 1  # the minimum sum in [1, n] we might miss

    while miss <= n:
      if i < len(nums) and nums[i] <= miss:
        miss += nums[i]
        i += 1
      else:
        # Greedily add `miss` itself to increase the range from
        # [1, miss) to [1, 2 * miss).
        miss += miss
        ans += 1

    return ans
