class Solution:
  def countSubranges(self, nums1: List[int], nums2: List[int]) -> int:
    kMod = 1_000_000_007
    ans = 0
    # {sum, count}, add if choose from nums1, minus if choose from nums2
    dp = Counter()

    for a, b in zip(nums1, nums2):
      newDp = Counter()
      newDp[a] += 1
      newDp[-b] += 1

      for prevSum, count in dp.items():
        # choose nums1[i]
        newDp[prevSum + a] += count
        newDp[prevSum + a] %= kMod
        # choose nums2[i]
        newDp[prevSum - b] += count
        newDp[prevSum - b] %= kMod

      dp = newDp
      ans += dp[0]
      ans %= kMod

    return ans
