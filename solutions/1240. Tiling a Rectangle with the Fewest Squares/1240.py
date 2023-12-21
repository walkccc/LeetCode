class Solution:
  def tilingRectangle(self, n: int, m: int) -> int:
    @functools.lru_cache(None)
    def dp(heights: int) -> int:
      minHeight = min(heights)
      if minHeight == n:  # All filled.
        return 0

      ans = m * n
      heightsList = list(heights)
      start = heightsList.index(minHeight)  # start index

      # Try to put square of different size that doesn't exceed the width/height.
      for sz in range(1, min(m - start + 1, n - minHeight + 1)):
        # heights[start:start + sz] must has the same height.
        if heights[start + sz - 1] != minHeight:
          break
        # Put a square of size `sz` to cover heights[start:start + sz].
        heightsList[start:start + sz] = [minHeight + sz] * sz
        ans = min(ans, dp(tuple(heightsList)))

      return 1 + ans

    return dp(tuple([0] * m))
