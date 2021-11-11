class Solution:
  def splitArray(self, nums: List[int], m: int) -> int:
    n = len(nums)
    prefix = [0] * (n + 1)

    for i in range(n):
      prefix[i + 1] = prefix[i] + nums[i]

    # dp(i, k) := min of largest sum to split first i nums into k groups
    @lru_cache(None)
    def dp(i: int, k: int) -> int:
      if k == 1:
        return prefix[i]

      ans = inf

      # try all possible partitions
      for j in range(k - 1, i):
        ans = min(ans, max(dp(j, k - 1), prefix[i] - prefix[j]))

      return ans

    return dp(n, m)
