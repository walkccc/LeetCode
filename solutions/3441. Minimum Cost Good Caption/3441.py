class Solution:

  def minCostGoodCaption(self, caption: str) -> str:
    n = len(caption)
    if n < 3:
      return ''

    MAX_COST = 1_000_000_000
    # dp[i][j][k] := the minimum cost of caption[i..n - 1], where j is the last
    # letter used, and k is the count of consecutive letters
    dp = [[[MAX_COST] * 3 for _ in range(26)] for _ in range(n)]

    for c in range(26):
      dp[-1][c][0] = abs(string.ascii_lowercase.index(caption[-1]) - c)

    minCost = MAX_COST

    for i in range(n - 2, -1, -1):
      newMinCost = MAX_COST
      for c in range(26):
        changeCost = abs(string.ascii_lowercase.index(caption[i]) - c)
        dp[i][c][0] = changeCost + minCost
        dp[i][c][1] = changeCost + dp[i + 1][c][0]
        dp[i][c][2] = changeCost + min(dp[i + 1][c][1], dp[i + 1][c][2])
        newMinCost = min(newMinCost, dp[i][c][2])
      minCost = newMinCost

    # Reconstruct the string.
    ans = []
    cost = MAX_COST
    letter = -1

    # Find the initial best letter.
    for c in range(25, -1, -1):
      if dp[0][c][2] <= cost:
        letter = c
        cost = dp[0][c][2]

    # Add the initial triplet.
    cost -= self._appendLetter(caption, 0, chr(ord('a') + letter), ans)
    cost -= self._appendLetter(caption, 1, chr(ord('a') + letter), ans)
    cost -= self._appendLetter(caption, 2, chr(ord('a') + letter), ans)

    # Build the rest of the string.
    i = 3
    while i < n:
      nextLetter = self._getNextLetter(dp, i, cost)
      if nextLetter < letter or min(dp[i][letter]) > cost:
        letter = nextLetter
        cost -= self._appendLetter(caption, i, chr(ord('a') + letter), ans)
        cost -= self._appendLetter(caption, i + 1, chr(ord('a') + letter), ans)
        cost -= self._appendLetter(caption, i + 2, chr(ord('a') + letter), ans)
        i += 3
      else:
        cost -= self._appendLetter(caption, i, chr(ord('a') + letter), ans)
        i += 1

    return ''.join(ans)

  def _getNextLetter(self, dp: list[list[list[int]]], i: int, cost: int) -> int:
    nextLetter = 26
    for c in range(25, -1, -1):
      if cost == dp[i][c][2]:
        nextLetter = c
    return nextLetter

  def _appendLetter(
      self,
      caption: str,
      i: int,
      letter: str,
      ans: list[str]
  ) -> int:
    ans.append(letter)
    return abs(ord(caption[i]) - ord(letter))
