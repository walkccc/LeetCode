class Solution:
  def minimumDistance(self, word: str) -> int:
    def dist(a: int, b: int) -> int:
      if a == 26:  # first hovering state
        return 0
      x1, y1 = a // 6, a % 6
      x2, y2 = b // 6, b % 6
      return abs(x1 - x2) + abs(y1 - y2)

    # dp(i, j, k) := min distance with left finger on i-th char and right finger on j-th char
    # that already have written k first words
    @functools.lru_cache(None)
    def dp(i: int, j: int, k: int) -> int:
      if k == len(word):
        return 0
      nxt = ord(word[k]) - ord('A')
      moveLeft = dist(i, nxt) + dp(nxt, j, k + 1)
      moveRight = dist(j, nxt) + dp(i, nxt, k + 1)
      return min(moveLeft, moveRight)

    return dp(26, 26, 0)
