class Solution:
  def executeInstructions(self, n: int, startPos: List[int], s: str) -> List[int]:
    moves = {'L': (0, -1), 'R': (0, 1), 'U': (-1, 0), 'D': (1, 0)}
    m = len(s)
    uMost = startPos[0] + 1
    dMost = n - startPos[0]
    lMost = startPos[1] + 1
    rMost = n - startPos[1]

    ans = [0] * m
    reach = {(0, None): m, (None, 0): m}
    x = 0
    y = 0

    for i in reversed(range(m)):
      dx, dy = moves[s[i]]
      x -= dx
      y -= dy
      reach[(x, None)] = i
      reach[(None, y)] = i
      out = min(reach.get((x - uMost, None), math.inf),
                reach.get((x + dMost, None), math.inf),
                reach.get((None, y - lMost), math.inf),
                reach.get((None, y + rMost), math.inf))
      ans[i] = m - i if out == math.inf else out - i - 1

    return ans
