class Solution:
  def minimumDistance(self, word: str) -> int:
    def dist(a: int, b: int) -> int:
      if a == 26:  # the first hovering state
        return 0
      x1, y1 = a // 6, a % 6
      x2, y2 = b // 6, b % 6
      return abs(x1 - x2) + abs(y1 - y2)

    @functools.lru_cache(None)
    def dp(i: int, j: int, k: int) -> int:
      """
      Returns the minimum distance to type the `word`, where the left finger is
      on the i-th letter, the right finger is on the j-th letter, and the
      words[0..k) have been written.
      """
      if k == len(word):
        return 0
      nxt = ord(word[k]) - ord('A')
      moveLeft = dist(i, nxt) + dp(nxt, j, k + 1)
      moveRight = dist(j, nxt) + dp(i, nxt, k + 1)
      return min(moveLeft, moveRight)

    return dp(26, 26, 0)
