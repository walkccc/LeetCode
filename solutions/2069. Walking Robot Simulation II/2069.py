class Robot:
  def __init__(self, width: int, height: int):
    self.isOrigin = True
    self.i = 0
    self.pos = [((0, 0), 'South')] + \
        [((i, 0), 'East') for i in range(1, width)] + \
        [((width - 1, j), 'North') for j in range(1, height)] + \
        [((i, height - 1), 'West') for i in range(width - 2, -1, -1)] +\
        [((0, j), 'South') for j in range(height - 2, 0, -1)]

  def step(self, num: int) -> None:
    self.isOrigin = False
    self.i = (self.i + num) % len(self.pos)

  def getPos(self) -> List[int]:
    return self.pos[self.i][0]

  def getDir(self) -> str:
    return 'East' if self.isOrigin else self.pos[self.i][1]
