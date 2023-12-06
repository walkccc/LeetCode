class Solution:
  def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
    dirs = [0, 1, 0, -1, 0]
    ans = [[-1] * n for _ in range(m)]
    x = 0  # the current x position
    y = 0  # the current y position
    d = 0

    curr = head
    while curr:
      ans[x][y] = curr.val
      if x + dirs[d] < 0 or x + dirs[d] == m or y + dirs[d + 1] < 0 or \
              y + dirs[d + 1] == n or ans[x + dirs[d]][y + dirs[d + 1]] != -1:
        d = (d + 1) % 4
      x += dirs[d]
      y += dirs[d + 1]
      curr = curr.next

    return ans
