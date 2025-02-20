class MinStack:
  def __init__(self):
    self.stack = []

  def push(self, x: int) -> None:
    mn = x if not self.stack else min(self.stack[-1][1], x)
    self.stack.append([x, mn])

  def pop(self) -> None:
    self.stack.pop()

  def top(self) -> int:
    return self.stack[-1][0]

  def getMin(self) -> int:
    return self.stack[-1][1]
