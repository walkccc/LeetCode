class Solution:
  def spiralMatrix(self, m: int, n: int, head: ListNode | None) -> list[list[int]]:
    DIRS = ((0, 1), (1, 0), (0, -1), (-1, 0))
    ans = [[-1] * n for _ in range(m)]
    x = 0  # the current x position
    y = 0  # the current y position
    d = 0

    curr = head
    while curr:
      ans[x][y] = curr.val
      if (x + DIRS[d][0] < 0 or x + DIRS[d][0] == m or y + DIRS[d][1] < 0 or
              y + DIRS[d][1] == n or ans[x + DIRS[d][0]][y + DIRS[d][1]] != -1):
        d = (d + 1) % 4
      x += DIRS[d][0]
      y += DIRS[d][1]
      curr = curr.next

    return ans
