class CustomStack:
  def __init__(self, maxSize: int):
    self.maxSize = maxSize
    self.stack = []
    # pendingIncrements[i] := the pending increment for stack[0..i].
    self.pendingIncrements = []

  def push(self, x: int) -> None:
    if len(self.stack) == self.maxSize:
      return
    self.stack.append(x)
    self.pendingIncrements.append(0)

  def pop(self) -> int:
    if not self.stack:
      return -1
    if len(self.stack) > 1:
      self.pendingIncrements[-2] += self.pendingIncrements[-1]
    return self.stack.pop() + self.pendingIncrements.pop()

  def increment(self, k: int, val: int) -> None:
    if not self.stack:
      return
    i = min(k - 1, len(self.stack) - 1)
    self.pendingIncrements[i] += val
