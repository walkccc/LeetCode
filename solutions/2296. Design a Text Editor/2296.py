class TextEditor:
  def __init__(self):
    self.s = []
    self.stack = []

  def addText(self, text: str) -> None:
    for c in text:
      self.s.append(c)

  def deleteText(self, k: int) -> int:
    numDeleted = min(k, len(self.s))
    for _ in range(numDeleted):
      self.s.pop()
    return numDeleted

  def cursorLeft(self, k: int) -> str:
    while self.s and k > 0:
      self.stack.append(self.s.pop())
      k -= 1
    return self._getString()

  def cursorRight(self, k: int) -> str:
    while self.stack and k > 0:
      self.s.append(self.stack.pop())
      k -= 1
    return self._getString()

  def _getString(self) -> str:
    if len(self.s) < 10:
      return ''.join(self.s)
    return ''.join(self.s[-10:])
