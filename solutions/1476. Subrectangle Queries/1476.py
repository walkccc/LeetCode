class SubrectangleQueries:
  def __init__(self, rectangle: list[list[int]]):
    self.rectangle = rectangle
    self.updates = []

  def updateSubrectangle(self, row1: int, col1: int, row2: int, col2: int,
                         newValue: int) -> None:
    self.updates.append((row1, col1, row2, col2, newValue))

  def getValue(self, row: int, col: int) -> int:
    for r1, c1, r2, c2, v in reversed(self.updates):
      if r1 <= row <= r2 and c1 <= col <= c2:
        return v
    return self.rectangle[row][col]
