class Solution:
  def splitArray(self, nums: list[int], k: int) -> int:
    prefix = list(itertools.accumulate(nums, initial=0))

    @functools.lru_cache(None)
    def dp(i: int, k: int) -> int:
      """
      Returns the minimum of the maximum sum to split the first i numbers into
      k groups.
      """
      if k == 1:
        return prefix[i]
      return min(max(dp(j, k - 1), prefix[i] - prefix[j])
                 for j in range(k - 1, i))

    return dp(len(nums), k)
