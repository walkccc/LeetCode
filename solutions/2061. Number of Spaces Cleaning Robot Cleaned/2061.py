class Solution:
  def numberOfCleanRooms(self, room: list[list[int]]) -> int:
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(room)
    n = len(room[0])
    ans = 1
    i = 0
    j = 0
    state = 0  # 0 := right, 1 := down, 2 := left, 3 := up
    seen = {(i, j, state)}
    room[i][j] = 2  # 2 := cleaned

    while True:
      x = i + dirs[state]
      y = j + dirs[state + 1]
      if x < 0 or x == m or y < 0 or y == n or room[x][y] == 1:
        # Turn 90 degrees clockwise.
        state = (state + 1) % 4
      else:
        # Walk to (x, y).
        if room[x][y] == 0:
          ans += 1
          room[x][y] = 2
        i = x
        j = y
      if (x, y, state) in seen:
        return ans
      seen.add((x, y, state))
