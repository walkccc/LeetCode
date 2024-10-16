class Solution:
  def __init__(self):
    self.kSize = 50
    self.kMax = 1_000_000
    self.dirs = ((1, 2), (2, 1), (2, -1), (1, -2),
                 (-1, -2), (-2, -1), (-2, 1), (-1, 2))

  def maxMoves(self, kx: int, ky: int, positions: list[list[int]]) -> int:
    n = len(positions)
    positions.append([kx, ky])
    hashedPositionToIndex = {}
    # dist[i][j] := the minimum distance from positions[i] to positions[j]
    dist = [[0] * (n + 1) for _ in range(n + 1)]

    for i, (x, y) in enumerate(positions):
      hashedPositionToIndex[self._hash(x, y)] = i

    for sourceIndex in range(n + 1):
      self._bfs(positions, sourceIndex, hashedPositionToIndex, dist)

    kMaxMask = 1 << (n + 1)
    # dp[i][mask][turn] := the maximum (Alice) or the minimum (Bob) cost to
    # kill all pawns, where i is the current pawn, mask is the set of pawns
    # that have been killed, and turn is the current player's turn (0 for Alice
    # and 1 for Bob)
    dp = [[[0, 0]
          for _ in range(1 << (n + 1))]
          for _ in range(n + 1)]

    for i in range(n + 1):
      for mask in range(kMaxMask - 1):
        dp[i][mask] = [-self.kMax, self.kMax]

    for mask in range(kMaxMask - 2, -1, -1):
      for i in range(n + 1):
        for turn in range(2):
          for j in range(n):
            if mask >> j & 1:
              continue
            moves = dist[i][j] + dp[j][mask | 1 << j][1 - turn]
            dp[i][mask][turn] = (max(dp[i][mask][turn], moves) if turn == 0 else
                                 min(dp[i][mask][turn], moves))

    # Returns the maximum cost to kill all pawns, i.e., the original positions
    # array without the knight (kx, ky).
    return dp[n][1 << n][0]

  def _hash(self, x: int, y: int) -> int:
    return x * self.kSize + y

  def _bfs(
      self,
      positions: list[list[int]],
      sourceIndex: int,
      hashedPositionToIndex: dict[int, int],
      dist: list[list[int]]
  ) -> None:
    """
    Computes the distance between positions[sourceIndex] and other positions.
    """
    sx, sy = positions[sourceIndex]
    q = collections.deque([(sx, sy)])
    seen = {(sx, sy)}
    seenPositions = 0

    step = 0
    while q and seenPositions < len(positions):
      for _ in range(len(q)):
        i, j = q.popleft()
        hashedPosition = self._hash(i, j)
        if hashedPosition in hashedPositionToIndex:
          dist[sourceIndex][hashedPositionToIndex[hashedPosition]] = step
          seenPositions += 1
        for dx, dy in self.dirs:
          x = i + dx
          y = j + dy
          if x < 0 or x >= self.kSize or y < 0 or y >= self.kSize:
            continue
          if (x, y) in seen:
            continue
          q.append((x, y))
          seen.add((x, y))
      step += 1
