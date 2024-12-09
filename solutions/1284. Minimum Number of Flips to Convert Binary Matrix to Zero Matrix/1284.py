class Solution:
  def minFlips(self, mat: list[list[int]]) -> int:
    m = len(mat)
    n = len(mat[0])
    hash = self._getHash(mat, m, n)
    if hash == 0:
      return 0

    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    step = 0
    q = collections.deque([hash])
    seen = {hash}

    while q:
      step += 1
      for _ in range(len(q)):
        curr = q.popleft()
        for i in range(m):
          for j in range(n):
            next = curr ^ 1 << (i * n + j)
            # Flie the four neighbors.
            for dx, dy in dirs:
              x = i + dx
              y = j + dy
              if x < 0 or x == m or y < 0 or y == n:
                continue
              next ^= 1 << (x * n + y)
            if next == 0:
              return step
            if next in seen:
              continue
            q.append(next)
            seen.add(next)

    return -1

  def _getHash(self, mat: list[list[int]], m: int, n: int) -> int:
    hash = 0
    for i in range(m):
      for j in range(n):
        if mat[i][j]:
          hash |= 1 << (i * n + j)
    return hash
