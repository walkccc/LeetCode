class Solution:
  def colorTheGrid(self, m: int, n: int) -> int:
    def getColor(mask: int, r: int) -> int:
      return mask >> r * 2 & 3

    def setColor(mask: int, r: int, color: int) -> int:
      return mask | color << r * 2

    kMod = 1_000_000_007

    @functools.lru_cache(None)
    def dp(r: int, c: int, prevColMask: int, currColMask: int) -> int:
      if c == n:
        return 1
      if r == m:
        return dp(0, c + 1, currColMask, 0)

      ans = 0

      # 1 := red, 2 := green, 3 := blue
      for color in range(1, 4):
        if getColor(prevColMask, r) == color:
          continue
        if r > 0 and getColor(currColMask, r - 1) == color:
          continue
        ans += dp(r + 1, c, prevColMask, setColor(currColMask, r, color))
        ans %= kMod

      return ans

    return dp(0, 0, 0, 0)
