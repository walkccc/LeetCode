class Solution:
  def removeBoxes(self, boxes: List[int]) -> int:
    # dp(i, j, k) := max score of boxes[i..j] if k boxes equal to boxes[j]
    @functools.lru_cache(None)
    def dp(i: int, j: int, k: int) -> int:
      if i > j:
        return 0

      r = j
      sameBoxes = k + 1
      while r > 0 and boxes[r - 1] == boxes[r]:
        r -= 1
        sameBoxes += 1
      ans = dp(i, r - 1, 0) + sameBoxes * sameBoxes

      for p in range(i, r):
        if boxes[p] == boxes[r]:
          ans = max(ans, dp(i, p, sameBoxes) + dp(p + 1, r - 1, 0))

      return ans

    return dp(0, len(boxes) - 1, 0)
