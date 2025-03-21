class Solution:
  def countSubranges(self, nums1: list[int], nums2: list[int]) -> int:
    MOD = 1_000_000_007
    ans = 0
    # {sum, count}, add if choose from nums1, minus if choose from nums2
    dp = collections.Counter()

    for a, b in zip(nums1, nums2):
      newDp = collections.Counter()
      newDp[a] += 1
      newDp[-b] += 1

      for prevSum, count in dp.items():
        # Choose nums1[i]
        newDp[prevSum + a] += count
        newDp[prevSum + a] %= MOD
        # Choose nums2[i]
        newDp[prevSum - b] += count
        newDp[prevSum - b] %= MOD

      dp = newDp
      ans += dp[0]
      ans %= MOD

    return ans
