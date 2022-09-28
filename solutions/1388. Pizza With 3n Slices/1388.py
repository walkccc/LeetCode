class Solution:
  def maxSizeSlices(self, slices: List[int]) -> int:
    # dp(i, j, k) := max sum of slices if you can pick k slices from slices[i:j]
    @functools.lru_cache(None)
    def dp(i: int, j: int, k: int) -> int:
      if k == 1:
        return max(slices[i:j])
      # Note that j - i is not the number of all the left slices. Since you
      # might have chosen not to take a slice in a previous step, there would be
      # leftovers outside [i:j]. If you take slices[i], one of the slices your
      # friends take will be outside of [i:j], so the length of [i:j] is reduced
      # by 2 instead of 3. Therefore, the min # is 2 * k - 1 (the last step only
      # requires one slice).
      if j - i < 2 * k - 1:
        return -math.inf
      return max(slices[i] + dp(i + 2, j, k - 1),
                 dp(i + 1, j, k))

    k = len(slices) // 3
    return max(dp(0, len(slices) - 1, k),
               dp(1, len(slices), k))
