class Solution:
  def snakesAndLadders(self, board: list[list[int]]) -> int:
    n = len(board)
    q = collections.deque([1])
    seen = set()
    arr = [0] * (1 + n * n)  # 2D -> 1D

    for i in range(n):
      for j in range(n):
        arr[(n - 1 - i) * n + (n - j if (n - i) % 2 == 0 else j + 1)] = board[i][j]

    step = 1
    while q:
      for _ in range(len(q)):
        curr = q.popleft()
        for next in range(curr + 1, min(curr + 6, n * n) + 1):
          dest = arr[next] if arr[next] > 0 else next
          if dest == n * n:
            return step
          if dest in seen:
            continue
          q.append(dest)
          seen.add(dest)
      step += 1

    return -1
