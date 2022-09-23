class Solution:
  def minFlips(self, mat: List[List[int]]) -> int:
    m = len(mat)
    n = len(mat[0])
    hashed = self._hash(mat, m, n)
    if hashed == 0:
      return 0

    dirs = [0, 1, 0, -1, 0]
    step = 0
    q = deque([hashed])
    seen = {hashed}

    while q:
      step += 1
      for _ in range(len(q)):
        curr = q.popleft()
        for i in range(m):
          for j in range(n):
            next = curr ^ 1 << (i * n + j)
            # flip four neighbors
            for k in range(4):
              x = i + dirs[k]
              y = j + dirs[k + 1]
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

  def _hash(self, mat: List[List[int]], m: int, n: int) -> int:
    hashed = 0
    for i in range(m):
      for j in range(n):
        if mat[i][j]:
          hashed |= 1 << (i * n + j)
    return hashed
